#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_pal(int start, int end, char *str )
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

void	ft_print_max_sub_pal(int start, int end, char *str)
{
	while (start <= end)
	{
		write (1, &str[start], 1);
		start++;
	}
}

void	ft_max_sub_pal(char *str)
{
	int	len = ft_strlen(str);
	int	max_sub_pal = 0;
	int	pal = 0;
	int	start;
	int	end;
	int	i;
	int	j;

	i = 0;
	while(i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (is_pal(i, j, str))
			{
				pal = j - i;
				if (pal >= max_sub_pal)
				{
					start = i;
					end = j;
					max_sub_pal = pal;
				}
			}
			j++;
		}
		i++;

	}
	ft_print_max_sub_pal(start, end, str);
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_max_sub_pal(argv[1]);
	else
		write (1, "\n", 1);
	return (0);
}
