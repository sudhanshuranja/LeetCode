class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;
        int mod = 12345;

        vector<int> arr(size);

        // Step 1: Flatten
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i * m + j] = grid[i][j] % mod;
            }
        }

        // Step 2: Prefix
        vector<int> prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }

        // Step 3: Suffix
        vector<int> suffix(size, 1);
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }

        // Step 4: Build result
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % mod;
            res[i / m][i % m] = val;
        }

        return res;
    }
};