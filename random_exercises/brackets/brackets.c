#include <unistd.h>

int	main(int argc, char **argv)
{
	char	c;
	char	stack[100];
	int	front;
	int	i;
	int	j;

	if (argc < 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		front = -1;
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (c == '(' || c == '[' || c == '{')
				stack[++front] = c;
			else if (c == ')' || c == ']' || c == '}')
			{
				if (front < 0)
				{
					front = 1;
					break ;
				}
				if (c == ')' && stack[front] == '(' 
						|| c == ']' && stack[front] == '[' 
						|| c == '}' && stack[front] == '{')
					front--;
				else
				{
					front = 1;
					break ;
				}
			}
			j++;
		}
		if (front == -1)
			write (1, "OK\n", 3);
		else
			write (1, "Error\n", 6);
		i++;
	}
	return (0);
}
