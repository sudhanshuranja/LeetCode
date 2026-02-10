class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Coordinate compression
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.erase(unique(sortedNums.begin(), sortedNums.end()), sortedNums.end());

        vector<int> comp(n);
        for (int i = 0; i < n; i++) {
            comp[i] = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
        }

        int m = sortedNums.size();

        // last seen arrays for even/odd
        vector<int> lastEven(m, -1), lastOdd(m, -1);

        for (int i = 0; i < n; i++) {
            int distinctEven = 0, distinctOdd = 0;

            for (int j = i; j < n; j++) {
                int idx = comp[j];

                if (nums[j] % 2 == 0) {
                    if (lastEven[idx] < i) {   // not seen in this subarray
                        lastEven[idx] = j;
                        distinctEven++;
                    }
                } else {
                    if (lastOdd[idx] < i) {    // not seen in this subarray
                        lastOdd[idx] = j;
                        distinctOdd++;
                    }
                }

                if (distinctEven == distinctOdd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
