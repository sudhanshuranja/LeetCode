/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var getBiggestThree = function(grid) {
    const m = grid.length, n = grid[0].length;
    const sums = new Set();

    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {

            // k = 0 rhombus
            sums.add(grid[r][c]);

            for (let k = 1; r-k >= 0 && r+k < m && c-k >= 0 && c+k < n; k++) {

                let sum = 0;

                // four edges
                for (let i = 0; i < k; i++) {
                    sum += grid[r-k+i][c+i];   // top-right
                    sum += grid[r+i][c+k-i];   // right-bottom
                    sum += grid[r+k-i][c-i];   // bottom-left
                    sum += grid[r-i][c-k+i];   // left-top
                }

                sums.add(sum);
            }
        }
    }

    return [...sums].sort((a,b)=>b-a).slice(0,3);
};