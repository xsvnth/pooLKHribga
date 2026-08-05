#include <unistd.h>

void	ft_show_options()
{
	write (1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}

int	main(int argc, char **argv)
{
	char	c;
	int	freq[32] = {0};
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			ft_show_options();
			return (0);
		}
		if (argv[i][1] == 'h')
		{
			ft_show_options();
			return (0);
		}
		j = 1;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 'a' && argv[i][j] <= 'z'))
			{
				write (1, "Invalid Option\n", 15);
				return (0);
			}
			else
				freq[argv[i][j] - 'a'] = 1;

			j++;
		}
		i++;
	}

	i = 31;
	while (i >= 0)
	{
		c = freq[i] + '0';
		write (1, &c, 1);
		i--;
		if ((i + 1) % 8 == 0 && (i + 1) > 0)
			write (1, " ", 1);
	}
	write (1, "\n", 1);
	return (0);
}
