#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> prefixGcd(n);
        int currentMax = 0;
        
        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);
            prefixGcd[i] = __gcd(nums[i], currentMax);
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long total = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            total += __gcd(prefixGcd[left], prefixGcd[right]);
            ++left;
            --right;
        }
        
        return total;
    }
};