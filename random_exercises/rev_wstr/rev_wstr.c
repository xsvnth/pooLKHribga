#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		int	i;
		int	len;
		len = ft_strlen(argv[1]);

		char	stuck[len];
		int	front = -1;

		i = len - 1;
		if (argv[1][i] == 32 || argv[1][i] == 9)
			i--;
		while (i >= 0)
		{
			while ((i >= 0) && argv[1][i] != 32 && argv[1][i] != 9)
			{
				stuck[++front] = argv[1][i];
				i--;
			}
			while (front >= 0)
				write (1, &stuck[front--], 1);
			if (i >= 0)
				write (1, " ", 1);
			i--;
		}
	}
	else
		write (1, "\n", 1);

	return (0);
}
