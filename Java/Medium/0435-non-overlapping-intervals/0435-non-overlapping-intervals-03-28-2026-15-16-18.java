class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        // Step 1: Sort by end time
        java.util.Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

        int count = 0;
        int prevEnd = intervals[0][1];

        // Step 2: Traverse
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlap → remove
                count++;
            } else {
                // No overlap → keep
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
}