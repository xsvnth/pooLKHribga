int solve(board, clues, pos)
{
    row = pos / 4;
    col = pos % 4;

    if (pos == 16)
        return (check_all(board, clues));

    value = 1;

    while (value <= 4)
    {
        if (can_place(board, row, col, value))
        {
            board[row][col] = value;

            if (solve(board, clues, pos + 1))
                return (1);

            board[row][col] = 0;
        }

        value++;
    }

    return (0);
}
