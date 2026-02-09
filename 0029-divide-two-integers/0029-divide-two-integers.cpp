class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case overflow: INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long to avoid overflow
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long ans = 0;

        // Bit shifting division
        while (a >= b) {
            long long temp = b, multiple = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        // Apply sign
        if (negative) ans = -ans;

        return (int)ans;
    }
};
