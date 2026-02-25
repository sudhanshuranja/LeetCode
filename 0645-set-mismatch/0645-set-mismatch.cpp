class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        vector<int> result(2);
        
        for(int num : nums) {
            freq[num]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2)
                result[0] = i;   // duplicate
            else if(freq[i] == 0)
                result[1] = i;   // missing
        }
        
        return result;
    }
};