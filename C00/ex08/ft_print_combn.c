/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:31:13 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/15 22:25:20 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char *num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write (1, &num[i], 1);
		i++;
	}
}

int	is_last_nb(char *num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (num[i] != ('0' + (10 - n + i)))
			return (0);
		i++;
	}
	return (1);
}

void	generate(int pos, int start, int n, char *num)
{
	int	digit;

	if (pos == n)
	{
		ft_print_char(num, n);
		if (!is_last_nb(num, n))
			write (1, ", ", 2);
		return ;
	}
	digit = start;
	while (digit <= 9)
	{
		num[pos] = (digit + '0');
		generate(pos + 1, digit + 1, n, num);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	num[10];

	generate (0, 0, n, num);
}
