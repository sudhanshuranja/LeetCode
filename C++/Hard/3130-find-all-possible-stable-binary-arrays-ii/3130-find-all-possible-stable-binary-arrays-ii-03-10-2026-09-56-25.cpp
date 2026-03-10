class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));

        vector<vector<int>> pref0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> pref1(zero + 1, vector<int>(one + 1, 0));

        // FIX 1: Establish the base cases so the DP can bootstrap
        pref0[0][0] = 1;
        pref1[0][0] = 1;

        for(int i = 0; i <= zero; i++) {
            for(int j = 0; j <= one; j++) {
                if(i == 0 && j == 0) continue;

                if(i > 0) {
                    int l = max(0, i - limit);
                    int r = i - 1;

                    int val = pref1[r][j];
                    if(l > 0) val = (val - pref1[l - 1][j] + MOD) % MOD;

                    dp0[i][j] = val;
                }

                if(j > 0) {
                    int l = max(0, j - limit);
                    int r = j - 1;

                    int val = pref0[i][r];
                    if(l > 0) val = (val - pref0[i][l - 1] + MOD) % MOD;

                    dp1[i][j] = val;
                }

                pref0[i][j] = dp0[i][j];
                pref1[i][j] = dp1[i][j];

                // FIX 2: Swap the prefix sum directions!
                // pref0 sums across the 'j' (ones) dimension
                if(j > 0) {
                    pref0[i][j] = (pref0[i][j] + pref0[i][j-1]) % MOD;
                }
                
                // pref1 sums across the 'i' (zeros) dimension
                if(i > 0) {
                    pref1[i][j] = (pref1[i][j] + pref1[i-1][j]) % MOD;
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};