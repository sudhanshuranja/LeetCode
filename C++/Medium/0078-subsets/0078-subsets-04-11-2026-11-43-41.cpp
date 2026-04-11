class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& nums, vector<int>& curr) {
        // Base case
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include element
        curr.push_back(nums[i]);
        solve(i + 1, nums, curr);

        // Backtrack
        curr.pop_back();

        // Exclude element
        solve(i + 1, nums, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(0, nums, curr);
        return ans;
    }
};