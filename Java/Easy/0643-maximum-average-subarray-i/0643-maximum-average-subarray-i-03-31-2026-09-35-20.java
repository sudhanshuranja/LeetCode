class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;

        long sum = 0;

        // initial window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long maxSum = sum;

        // sliding window
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = Math.max(maxSum, sum);
        }

        return (double) maxSum / k;
    }
}