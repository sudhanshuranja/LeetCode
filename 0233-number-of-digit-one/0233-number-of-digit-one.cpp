class Solution {
public:
    int countDigitOne(int n) {
        long long factor = 1;
        long long count = 0;

        while (factor <= n) {
            long long high = n / (factor * 10);
            long long current = (n / factor) % 10;
            long long low = n % factor;

            if (current == 0) {
                count += high * factor;
            }
            else if (current == 1) {
                count += high * factor + (low + 1);
            }
            else {
                count += (high + 1) * factor;
            }

            factor *= 10;
        }

        return count;
    }
};