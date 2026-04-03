import java.util.Arrays;

class Solution {
    public int maxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.length;
        
        // Bind robot positions and distances together, then sort by position
        int[][] robs = new int[n][2];
        for (int i = 0; i < n; i++) {
            robs[i][0] = robots[i];
            robs[i][1] = distance[i];
        }
        Arrays.sort(robs, (a, b) -> Integer.compare(a[0], b[0]));
        
        // Extract sorted positions for fast binary search
        int[] sorted_robs = new int[n];
        for (int i = 0; i < n; i++) {
            sorted_robs[i] = robs[i][0];
        }
        
        // 1. Separate walls unconditionally destroyed (sharing position with a robot)
        int base_walls = 0;
        int[] temp_walls = new int[walls.length];
        int count = 0;
        
        for (int w : walls) {
            if (Arrays.binarySearch(sorted_robs, w) >= 0) {
                base_walls++;
            } else {
                temp_walls[count++] = w;
            }
        }
        
        // Clean walls strictly sitting in the open segments between/outside robots
        int[] clean_walls = Arrays.copyOf(temp_walls, count);
        Arrays.sort(clean_walls);
        
        // dp[i][0] -> Max walls destroyed up to segment i-1, with robot i shooting LEFT
        // dp[i][1] -> Max walls destroyed up to segment i-1, with robot i shooting RIGHT
        int[][] dp = new int[n][2];
        
        // Segment 0 (Left of the first robot)
        int L0 = robs[0][0] - robs[0][1];
        int R0 = robs[0][0] - 1;
        dp[0][0] = countWalls(clean_walls, L0, R0);
        dp[0][1] = 0; // Shooting right doesn't affect the left segment
        
        // Process segments between robots
        for (int i = 1; i < n; i++) {
            int r_prev = robs[i-1][0], d_prev = robs[i-1][1];
            int r_curr = robs[i][0],   d_curr = robs[i][1];
            
            // Define interval ranges restricted by adjacent robots
            int prev_R_start = r_prev + 1;
            int prev_R_end   = Math.min(r_prev + d_prev, r_curr - 1);
            
            int curr_L_start = Math.max(r_curr - d_curr, r_prev + 1);
            int curr_L_end   = r_curr - 1;
            
            // Single direction counts
            int w_LL = countWalls(clean_walls, curr_L_start, curr_L_end);
            int w_LR = 0; // Neither shoots into the segment
            int w_RR = countWalls(clean_walls, prev_R_start, prev_R_end);
            
            // Both shoot inwards (Right then Left). Subtract intersection to prevent Double Counting!
            int overlap_start = Math.max(prev_R_start, curr_L_start);
            int overlap_end   = Math.min(prev_R_end, curr_L_end);
            int w_overlap     = countWalls(clean_walls, overlap_start, overlap_end);
            
            int w_RL = w_RR + w_LL - w_overlap;
            
            // DP Transitions
            dp[i][0] = Math.max(dp[i-1][0] + w_LL, dp[i-1][1] + w_RL);
            dp[i][1] = Math.max(dp[i-1][0] + w_LR, dp[i-1][1] + w_RR);
        }
        
        // Segment N (Right of the last robot)
        int last_start = robs[n-1][0] + 1;
        int last_end   = robs[n-1][0] + robs[n-1][1];
        int w_last     = countWalls(clean_walls, last_start, last_end);
        
        // Find max from the final states mapping to the end of the arrays
        int max_additional = Math.max(dp[n-1][0], dp[n-1][1] + w_last);
        
        return base_walls + max_additional;
    }
    
    // Binary search helper to count elements strictly within [L, R]
    private int countWalls(int[] arr, int L, int R) {
        if (L > R) return 0;
        int leftIdx = lowerBound(arr, L);
        int rightIdx = upperBound(arr, R);
        return Math.max(0, rightIdx - leftIdx);
    }
    
    private int lowerBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    private int upperBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
}