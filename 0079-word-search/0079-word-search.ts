function exist(board: string[][], word: string): boolean {
    const m = board.length, n = board[0].length, w = word.length;

    const next = (y: number, x: number, idx: number): boolean => {
        if (idx === w) return true;
        const char = word[idx];
        board[y][x] = '';
        if (
            x > 0 && board[y][x - 1] === char && next(y, x - 1, idx + 1) ||
            y > 0 && board[y - 1][x] === char && next(y - 1, x, idx + 1) ||
            x < n - 1 && board[y][x + 1] === char && next(y, x + 1, idx + 1) ||
            y < m - 1 && board[y + 1][x] === char && next(y + 1, x, idx + 1)
        ) return true;
        board[y][x] = word[idx - 1];
        return false;
    }

    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            if (board[i][j] === word[0] && next(i, j, 1)) return true;

    return false;
};