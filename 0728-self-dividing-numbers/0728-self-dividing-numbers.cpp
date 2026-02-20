#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        for (int num = left; num <= right; num++) {
            int temp = num;
            bool isValid = true;
            
            while (temp > 0) {
                int digit = temp % 10;
                
                // If digit is 0 or not dividing the number
                if (digit == 0 || num % digit != 0) {
                    isValid = false;
                    break;
                }
                
                temp /= 10;
            }
            
            if (isValid)
                result.push_back(num);
        }
        
        return result;
    }
};