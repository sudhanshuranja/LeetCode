class Solution {
    public boolean canJump(int[] nums) {
        int maxReach = 0;
        
        for (int i = 0; i < nums.length; i++) {
            // If current index is unreachable
            if (i > maxReach) {
                return false;
            }
            
            // Update max reach
            maxReach = Math.max(maxReach, i + nums[i]);
        }
        
        return true;
    }
}