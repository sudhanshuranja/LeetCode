class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        // Step 1: Store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Step 2: Process each value
        for (auto &p : mp) {
            vector<int> &v = p.second;
            
            if (v.size() < 3) continue;
            
            // Step 3: Sliding window of size 3
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};