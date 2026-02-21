class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        
        // Mark primes up to 20
        bool isPrime[21] = {false};
        isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = true;
        isPrime[11] = isPrime[13] = isPrime[17] = isPrime[19] = true;
        
        int count = 0;
        
        for(int i = left; i <= right; i++) {
            int bits = __builtin_popcount(i);
            if(isPrime[bits])
                count++;
        }
        
        return count;
    }
};