class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        // Step 1: Total sum
        for (auto &row : grid)
            for (int x : row)
                total += x;

        // If total is odd → impossible
        if (total % 2 != 0) return false;

        // Step 2: Horizontal cuts
        long long rowSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum * 2 == total) return true;
        }

        // Step 3: Vertical cuts
        vector<long long> colSum(n, 0);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }

        long long prefixCol = 0;
        for (int j = 0; j < n - 1; j++) {
            prefixCol += colSum[j];
            if (prefixCol * 2 == total) return true;
        }

        return false;
    }
};