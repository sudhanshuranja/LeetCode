#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // If k divisible by 2 or 5 → impossible
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        
        int remainder = 0;
        
        for (int length = 1; length <= k; length++) {
            remainder = (remainder * 10 + 1) % k;
            
            if (remainder == 0)
                return length;
        }
        
        return -1; // Should not reach here logically
    }
};