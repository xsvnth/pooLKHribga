#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	found_king(char **argv, int rows, int cols, int *rk, int *ck)
{
	char	c;
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			c = argv[i][j];
			if (c == 'K')
			{
				*rk = i;
				*ck = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	check_pawn(int rk, int ck, int r, int c, char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			if (argv[i][j] == 'P')
			{
				if (i + 1 == rk && (j + 1 == ck || j - 1 == ck))
						return (1);
			//	else if (i - 1 == rk && (j + 1 == ck || j - 1 == ck))
			//			return (1);
			}
			j++;
		}
		i++;
	}
	return (0);

}

int	check_rook(int rk, int ck, int r, int c, char **argv)
{
	int	i;
	int	row_len;
	
	row_len = ft_strlen(argv[rk]);

	i = rk - 1;
	while (i >= 0)
	{
		if (argv[i][ck] == 'R' || argv[i][ck] == 'Q')
			return (1);
		else if (argv[i][ck] != '.')
			break ;
		i--;
	}
	i = rk + 1;
	while (i < r)
	{
		if (argv[i][ck] == 'R' || argv[i][ck] == 'Q')
			return (1);
		else if (argv[i][ck] != '.')
			break ;
		i++;

	}
	i = ck + 1;
	while (i < r)
	{
		if (argv[rk][i] == 'R' || argv[rk][i] == 'Q')
			return (1);
		else if (argv[rk][i] != '.')
			break ;
		i++;
	}
	i = ck - 1;
	while (i >= 0)
	{
		if (argv[rk][i] == 'R' || argv[rk][i] == 'Q')
			return (1);
		else if (argv[rk][i] != '.')
			break ;
		i--;
	}
	return (0);
}

int	check_bishop(int rk, int ck, int r, int c, char **argv)
{
	int	i;
	int	j;

	i = rk - 1;
	j = ck + 1;//up r
	while (i >= 0 && j < c)
	{
		if (argv[i][j] == 'B' || argv[i][j] == 'Q')
			return (1);
		else if (argv[i][j] != '.')
			break ;
		i--;
		j++;
	}
	i = rk - 1;
	j = ck - 1;//up l
	while (i >= 0 && j >= 0)
	{
		if (argv[i][j] == 'B' || argv[i][j] == 'Q')
			return (1);
		else if (argv[i][j] != '.')
			break ;
		i--;
		j--;
	}
	i = rk + 1;
	j = ck + 1;//down r
	while (i < r && j < c)
	{
		if (argv[i][j] == 'B' || argv[i][j] == 'Q')
			return (1);
		else if (argv[i][j] != '.')
			break ;
		i++;
		j++;
	}
	i = rk + 1;
	j = ck - 1;// down l
	while (i < r && j >= 0)
	{
		if (argv[i][j] == 'B' || argv[i][j] == 'Q')
			return (1);
		else if (argv[i][j] != '.')
			break ;
		i++;
		j--;
	}
	return (0);
}

int	check_queen(int rk, int ck, int r, int c, char **argv)
{
	if (check_rook(rk, ck, r, c, argv) || check_bishop(rk, ck, r, c, argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	rk;
	int	ck;
	int	r;
	int	c; 

	if (argc < 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	argv++;
	r = argc - 1;
	c = ft_strlen(argv[0]);
	found_king(argv,r ,c ,&rk ,&ck);

	if (check_pawn(rk, ck, r, c, argv)
		|| check_rook(rk, ck, r, c, argv)
		|| check_bishop(rk, ck, r, c, argv)
		|| check_queen(rk, ck, r, c, argv))
		write (	1, "Success\n", 8);
	else
		write (	1, "Fail\n", 5);

	return (0);
}
