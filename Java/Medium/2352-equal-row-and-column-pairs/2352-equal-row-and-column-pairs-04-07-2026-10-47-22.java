import java.util.*;

class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;

        // Step 1: Store rows in hashmap
        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < n; j++) {
                row.append(grid[i][j]).append(",");
            }
            String key = row.toString();
            map.put(key, map.getOrDefault(key, 0) + 1);
        }

        // Step 2: Check columns
        int count = 0;

        for (int j = 0; j < n; j++) {
            StringBuilder col = new StringBuilder();
            for (int i = 0; i < n; i++) {
                col.append(grid[i][j]).append(",");
            }
            String key = col.toString();

            count += map.getOrDefault(key, 0);
        }

        return count;
    }
}