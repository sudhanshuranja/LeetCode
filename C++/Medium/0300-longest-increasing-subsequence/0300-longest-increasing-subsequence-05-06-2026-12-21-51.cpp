class MaxBIT {
    vector<int> bit;
public:
    MaxBIT(int size) {
        bit.resize(size + 1);
    }
    int get(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx)
            ans = max(ans, bit[idx]);
        return ans;
    }
    void update(int idx, int val) {
        for (; idx < bit.size(); idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
};
class Solution { // 12 ms, faster than 75.90%
public:
    int lengthOfLIS(vector<int>& nums) {
        int nUnique = compress(nums);
        MaxBIT bit(nUnique);
        for (int x : nums) {
            int subLongest = bit.get(x - 1);
            bit.update(x, subLongest + 1);
        }
        return bit.get(nUnique);
    }
    int compress(vector<int>& arr) {
        vector<int> uniqueSorted(arr);
        sort(uniqueSorted.begin(), uniqueSorted.end());
        uniqueSorted.erase(unique(uniqueSorted.begin(), uniqueSorted.end()), uniqueSorted.end()); // Remove duplicated values
        for (int& x : arr) x = lower_bound(uniqueSorted.begin(), uniqueSorted.end(), x) - uniqueSorted.begin() + 1;
        return uniqueSorted.size();
    }
};