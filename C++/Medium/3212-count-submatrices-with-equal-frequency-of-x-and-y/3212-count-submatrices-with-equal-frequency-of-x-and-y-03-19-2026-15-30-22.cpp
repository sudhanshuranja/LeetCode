class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> prefixX(m, vector<int>(n, 0));
        vector<vector<int>> prefixY(m, vector<int>(n, 0));
        
        // Build prefix sum for X and Y
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = (grid[i][j] == 'X');
                int y = (grid[i][j] == 'Y');
                
                prefixX[i][j] = x;
                prefixY[i][j] = y;
                
                if (i > 0) {
                    prefixX[i][j] += prefixX[i-1][j];
                    prefixY[i][j] += prefixY[i-1][j];
                }
                if (j > 0) {
                    prefixX[i][j] += prefixX[i][j-1];
                    prefixY[i][j] += prefixY[i][j-1];
                }
                if (i > 0 && j > 0) {
                    prefixX[i][j] -= prefixX[i-1][j-1];
                    prefixY[i][j] -= prefixY[i-1][j-1];
                }
            }
        }
        
        int ans = 0;
        
        // Check all submatrices from (0,0)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int countX = prefixX[i][j];
                int countY = prefixY[i][j];
                
                if (countX == countY && countX > 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};