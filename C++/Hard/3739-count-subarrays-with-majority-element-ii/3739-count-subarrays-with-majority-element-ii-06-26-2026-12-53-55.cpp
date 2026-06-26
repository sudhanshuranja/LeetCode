class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        vector<int> bit(m + 2, 0);

        auto update = [&](int idx) {
            while (idx <= m) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        long long ans = 0;

        for (int x : prefix) {
            int id = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            ans += query(id - 1);
            update(id);
        }

        return ans;
    }
};