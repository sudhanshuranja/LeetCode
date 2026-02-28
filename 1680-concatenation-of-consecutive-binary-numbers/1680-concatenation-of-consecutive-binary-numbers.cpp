class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long result = 0;
        int bit_length = 0;

        for(int i = 1; i <= n; i++) {

            // Check if i is power of 2
            if((i & (i - 1)) == 0) {
                bit_length++;
            }

            result = ((result << bit_length) | i) % MOD;
        }

        return result;
    }
};