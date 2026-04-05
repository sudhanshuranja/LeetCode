class Solution {
    public int jump(int[] nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        // No need to go till last index
        for (int i = 0; i < nums.length - 1; i++) {
            
            // Update farthest reachable index
            farthest = Math.max(farthest, i + nums[i]);
            
            // If we reach end of current range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        
        return jumps;
    }
}