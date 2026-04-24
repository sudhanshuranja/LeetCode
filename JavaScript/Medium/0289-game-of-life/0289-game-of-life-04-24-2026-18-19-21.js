var gameOfLife = function(board) {
    const m = board.length, n = board[0].length;

    const countLive = (r, c) => {
        let count = 0;
        for (let dr = -1; dr <= 1; dr++) {
            for (let dc = -1; dc <= 1; dc++) {
                if (dr === 0 && dc === 0) continue;
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && Math.abs(board[nr][nc]) === 1)
                    count++;
            }
        }
        return count;
    };

    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            const live = countLive(r, c);
            if (board[r][c] === 1 && (live < 2 || live > 3)) board[r][c] = -1;
            if (board[r][c] === 0 && live === 3) board[r][c] = 2;
        }
    }

    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            board[r][c] = board[r][c] > 0 ? 1 : 0;
        }
    }
};