#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = nb % 10 + '0';
	write (1, &c, 1);
}

int	is_sep(char c)
{
	return (c == ' ');
}

int	is_opr(char c)
{
	char str[] = "-+*/%";
	int i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	stack[100];	
	int	front = -1;
	int	opr;
	int	i = 0;

	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	while (argv[1][i])
	{
		while (argv[1][i] && is_sep(argv[1][i]))
				i++;
		if ((argv[1][i] == '-' && is_number(argv[1][i + 1])) || is_number(argv[1][i]))
		{
			stack[++front] = atoi(&argv[1][i]);
			if (argv[1][i] == '-')
				i++;
			while (is_number(argv[1][i]))
				i++;
		}
		else if (is_opr(argv[1][i]))
		{
			if (front < 1)
			{
				if (front < 1)
				write(1, "Error\n", 6);
				return (0);
			}
			if (argv[1][i] == '+')
				opr = stack[front] + stack[front - 1];	
			else if (argv[1][i] == '-')
				opr = stack[front - 1] - stack[front];	
			else if (argv[1][i] == '*')
				opr = stack[front] * stack[front - 1];	
			else if (argv[1][i] == '/')
				opr = stack[front - 1] / stack[front];	
			else if (argv[1][i] == '%')
				opr = stack[front - 1] % stack[front];	
			stack[--front] = opr;
			i++;
		}
		else if (argv[1][i])
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (front != 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_putnbr(stack[front]);
	write (1, "\n", 1);
	return (0);
}
