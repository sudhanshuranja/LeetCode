class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // Allocate ALL vectors globally once to avoid heap allocation overhead in the loop
        vector<long long> up(m + 2, 1);
        vector<long long> down(m + 2, 1);
        vector<long long> newUp(m + 2, 0);
        vector<long long> newDown(m + 2, 0);
        vector<long long> prefDown(m + 2, 0);
        vector<long long> suffUp(m + 2, 0);

        // DP Transitions
        for (int len = 2; len <= n; len++) {
            // Compute prefix sums of 'down'
            prefDown[0] = 0;
            for (int i = 1; i <= m; i++) {
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            // Compute suffix sums of 'up'
            suffUp[m + 1] = 0;
            for (int i = m; i >= 1; i--) {
                suffUp[i] = (suffUp[i + 1] + up[i]) % MOD;
            }

            // Populate the new states directly into pre-allocated memory
            for (int y = 1; y <= m; y++) {
                newUp[y] = prefDown[y - 1];
                newDown[y] = suffUp[y + 1];
            }

            // Use fast pointer swaps to recycle vectors instead of destroying them
            up.swap(newUp);
            down.swap(newDown);
        }

        // Collect the final answer
        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};