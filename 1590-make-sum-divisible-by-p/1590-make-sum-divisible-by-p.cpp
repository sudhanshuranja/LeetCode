class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(int num : nums)
            total += num;

        int target = total % p;
        if(target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int minLen = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int currMod = prefix % p;

            int needed = (currMod - target + p) % p;

            if(mp.count(needed)) {
                minLen = min(minLen, i - mp[needed]);
            }

            mp[currMod] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};