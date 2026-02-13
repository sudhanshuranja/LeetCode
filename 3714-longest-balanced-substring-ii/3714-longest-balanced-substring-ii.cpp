#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = (int)s.size();
        int ans = 1;

        // -------------------- Case 1: Single character runs --------------------
        int run = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) run++;
            else run = 1;
            ans = max(ans, run);
        }

        // -------------------- Case 2: Exactly 2 distinct characters --------------------
        auto solveTwo = [&](char x, char y, char bad) {
            int best = 0;
            int i = 0;
            while (i < n) {
                while (i < n && s[i] == bad) i++;
                if (i >= n) break;

                int j = i;
                while (j < n && s[j] != bad) j++;

                unordered_map<int, int> first;
                first.reserve((j - i) * 2 + 5);

                int cx = 0, cy = 0;
                first[0] = i - 1;

                for (int k = i; k < j; k++) {
                    if (s[k] == x) cx++;
                    else if (s[k] == y) cy++;

                    int diff = cx - cy;
                    if (!first.count(diff)) first[diff] = k;
                    else best = max(best, k - first[diff]);
                }

                i = j;
            }
            return best;
        };

        ans = max(ans, solveTwo('a', 'b', 'c'));
        ans = max(ans, solveTwo('a', 'c', 'b'));
        ans = max(ans, solveTwo('b', 'c', 'a'));

        // -------------------- Case 3: All 3 characters present --------------------
        struct PairHash {
            size_t operator()(const pair<int,int>& p) const {
                return ((uint64_t)(uint32_t)p.first << 32) ^ (uint32_t)p.second;
            }
        };

        unordered_map<pair<int,int>, int, PairHash> mp;
        mp.reserve(n * 2 + 5);

        int ca = 0, cb = 0, cc = 0;
        mp[{0, 0}] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else cc++;

            pair<int,int> key = {cb - ca, cc - ca};

            if (!mp.count(key)) mp[key] = i;
            else ans = max(ans, i - mp[key]);
        }

        return ans;
    }
};
