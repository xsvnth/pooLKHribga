int parse_input(char *str, int clues[]);
int solve(int board[4][4], int clues[], int pos);
void print_board(int board[4][4]);
void print_error(void);

int main(int argc, char **argv)
{
    int clues[16];
    int board[4][4];
    int i;
    int j;

    if (argc != 2)
    {
        print_error();
        return (0);
    }

    if (!parse_input(argv[1], clues))
    {
        print_error();
        return (0);
    }

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            board[i][j] = 0;
            j++;
        }
        i++;
    }

    if (solve(board, clues, 0))
        print_board(board);
    else
        print_error();
}
