#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        // Pair up robots and their distances so we can sort them by position
        vector<pair<long long, long long>> rd(n);
        for(int i = 0; i < n; ++i) {
            rd[i] = {robots[i], distance[i]};
        }
        sort(rd.begin(), rd.end());

        vector<long long> R(n), D(n);
        for(int i = 0; i < n; ++i) {
            R[i] = rd[i].first;
            D[i] = rd[i].second;
        }

        // Sort walls to allow for binary search counts
        sort(walls.begin(), walls.end());

        // Helper lambda to count walls exclusively inside range [L, R_val]
        auto count_walls = [&](long long L, long long R_val) -> int {
            if(L > R_val) return 0;
            auto it1 = lower_bound(walls.begin(), walls.end(), L);
            auto it2 = upper_bound(walls.begin(), walls.end(), R_val);
            return it2 - it1;
        };

        // 1. Account for walls standing exactly on top of robots
        int walls_at_robots = 0;
        for(int i = 0; i < n; ++i) {
            walls_at_robots += count_walls(R[i], R[i]);
        }

        // Arrays to hold interval values strictly between robots
        vector<int> S(n), P(n), C(n);
        for(int i = 0; i < n; ++i) {
            long long L_bound = R[i] - D[i];
            if(i > 0) {
                L_bound = max(L_bound, R[i-1] + 1); // Bullet bounded by previous robot
            }
            S[i] = count_walls(L_bound, R[i] - 1);

            long long R_bound = R[i] + D[i];
            if(i + 1 < n) {
                R_bound = min(R_bound, R[i+1] - 1); // Bullet bounded by next robot
            }
            P[i] = count_walls(R[i] + 1, R_bound);

            if(i > 0) {
                C[i] = count_walls(R[i-1] + 1, R[i] - 1);
            }
        }

        // dp[i][0] -> Max walls destroyed up to Robot i, assuming Robot i shoots Left
        // dp[i][1] -> Max walls destroyed up to Robot i, assuming Robot i shoots Right
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = S[0];
        dp[0][1] = 0;

        for(int i = 1; i < n; ++i) {
            // Calculate segment contribution costs based on directional combinations
            int cost_LL = S[i];
            int cost_LR = 0;
            int cost_RL = min(C[i], P[i-1] + S[i]); // Resolves overlapping shots correctly
            int cost_RR = P[i-1];

            dp[i][0] = max(dp[i-1][0] + cost_LL, dp[i-1][1] + cost_RL);
            dp[i][1] = max(dp[i-1][0] + cost_LR, dp[i-1][1] + cost_RR);
        }

        // dp[n-1][0] resolves completely. dp[n-1][1] needs P[n-1] added because 
        // the right-shooting interval stretching to infinity is uniquely the last robot's.
        int max_open_intervals = max(dp[n-1][0], dp[n-1][1] + P[n-1]);
        
        return max_open_intervals + walls_at_robots;
    }
};