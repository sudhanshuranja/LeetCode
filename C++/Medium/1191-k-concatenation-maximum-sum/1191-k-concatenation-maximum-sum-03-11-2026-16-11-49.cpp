class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int MOD = 1e9 + 7;

        long totalSum = 0;
        for (int x : arr) totalSum += x;

        long curr = 0, maxSum = 0;

        int n = arr.size();

        // Run Kadane on 2 concatenations without building array
        for (int i = 0; i < n * min(2, k); i++) {
            curr = max((long)arr[i % n], curr + arr[i % n]);
            maxSum = max(maxSum, curr);
        }

        if (totalSum > 0 && k > 2) {
            maxSum += (long)(k - 2) * totalSum;
        }

        return maxSum % MOD;
    }
};