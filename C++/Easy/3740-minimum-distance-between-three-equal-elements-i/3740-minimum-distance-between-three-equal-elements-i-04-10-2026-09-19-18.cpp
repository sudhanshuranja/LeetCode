class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Process each number
        for (auto &it : mp) {
            vector<int> &v = it.second;

            if (v.size() < 3) continue;

            // Check all triplets of consecutive indices
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};