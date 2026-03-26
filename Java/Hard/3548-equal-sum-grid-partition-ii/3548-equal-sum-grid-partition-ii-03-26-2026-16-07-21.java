import java.util.*;

class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        long totalSum = 0;
        
        // Count total sum and global frequencies
        Map<Integer, Integer> allFreq = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
                allFreq.put(grid[i][j], allFreq.getOrDefault(grid[i][j], 0) + 1);
            }
        }

        // 1. Check Horizontal Cuts
        if (checkHorizontal(grid, m, n, totalSum, new HashMap<>(allFreq))) return true;

        // 2. Check Vertical Cuts
        if (checkVertical(grid, m, n, totalSum, new HashMap<>(allFreq))) return true;

        return false;
    }

    private boolean checkHorizontal(int[][] grid, int m, int n, long totalSum, Map<Integer, Integer> botFreq) {
        long topSum = 0;
        Map<Integer, Integer> topFreq = new HashMap<>();

        for (int i = 0; i < m - 1; i++) {
            // Move current row from bottom section to top section
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                topSum += val;
                topFreq.put(val, topFreq.getOrDefault(val, 0) + 1);
                
                botFreq.put(val, botFreq.get(val) - 1);
                if (botFreq.get(val) == 0) botFreq.remove(val);
            }

            long botSum = totalSum - topSum;

            // Option A: Sums are already equal
            if (topSum == botSum) return true;

            // Option B: Discount from Top to match Bottom
            long diffTop = topSum - botSum;
            if (diffTop > 0 && diffTop <= 100000) {
                if (canRemove(grid, (int)diffTop, i + 1, n, topFreq, i, true, true)) return true;
            }

            // Option C: Discount from Bottom to match Top
            long diffBot = botSum - topSum;
            if (diffBot > 0 && diffBot <= 100000) {
                if (canRemove(grid, (int)diffBot, m - 1 - i, n, botFreq, i + 1, false, true)) return true;
            }
        }
        return false;
    }

    private boolean checkVertical(int[][] grid, int m, int n, long totalSum, Map<Integer, Integer> rightFreq) {
        long leftSum = 0;
        Map<Integer, Integer> leftFreq = new HashMap<>();

        for (int j = 0; j < n - 1; j++) {
            // Move current column from right section to left section
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                leftSum += val;
                leftFreq.put(val, leftFreq.getOrDefault(val, 0) + 1);
                
                rightFreq.put(val, rightFreq.get(val) - 1);
                if (rightFreq.get(val) == 0) rightFreq.remove(val);
            }

            long rightSum = totalSum - leftSum;

            if (leftSum == rightSum) return true;

            // Discount from Left
            long diffL = leftSum - rightSum;
            if (diffL > 0 && diffL <= 100000) {
                if (canRemove(grid, (int)diffL, m, j + 1, leftFreq, j, true, false)) return true;
            }

            // Discount from Right
            long diffR = rightSum - leftSum;
            if (diffR > 0 && diffR <= 100000) {
                if (canRemove(grid, (int)diffR, m, n - 1 - j, rightFreq, j + 1, false, false)) return true;
            }
        }
        return false;
    }

    private boolean canRemove(int[][] grid, int target, int rows, int cols, Map<Integer, Integer> freq, int startIdx, boolean isFirstPart, boolean isHorizontalCut) {
        if (!freq.containsKey(target)) return false;
        
        // Connectivity Rule:
        // If the section is a single line (1 row or 1 col), 
        // the cell must be an endpoint to keep the rest connected.
        if (isHorizontalCut) {
            if (rows > 1 && cols > 1) return true; // Thick block: any cell removal stays connected
            if (rows == 1) return (grid[startIdx][0] == target || grid[startIdx][cols - 1] == target);
            if (cols == 1) {
                int firstRow = isFirstPart ? 0 : startIdx;
                int lastRow = isFirstPart ? startIdx : grid.length - 1;
                return (grid[firstRow][0] == target || grid[lastRow][0] == target);
            }
        } else {
            // Vertical Cut logic
            if (rows > 1 && cols > 1) return true;
            if (cols == 1) return (grid[0][startIdx] == target || grid[rows - 1][startIdx] == target);
            if (rows == 1) {
                int firstCol = isFirstPart ? 0 : startIdx;
                int lastCol = isFirstPart ? startIdx : grid[0].length - 1;
                return (grid[0][firstCol] == target || grid[0][lastCol] == target);
            }
        }
        return true;
    }
}