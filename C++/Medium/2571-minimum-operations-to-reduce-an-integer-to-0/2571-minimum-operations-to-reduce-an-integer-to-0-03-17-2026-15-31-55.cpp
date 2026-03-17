class Solution {
public:
    int minOperations(int n) {
        int operations = 0;
        
        while (n > 0) {
            if ((n & 3) == 3) {
                n++;
                operations++;
            } else if ((n & 1) == 1) {
                n--;
                operations++;
            }
            n >>= 1;
        }
        
        return operations;
    }
};