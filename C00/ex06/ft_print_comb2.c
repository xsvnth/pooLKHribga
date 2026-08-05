/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:03:31 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/18 00:22:40 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_comb2(int a, int b)
{
	char	dev;
	char	mod;

	dev = (a / 10) + '0';
	mod = (a % 10) + '0';
	write (1, &dev, 1);
	write (1, &mod, 1);
	write (1, " ", 1);
	dev = (b / 10) + '0';
	mod = (b % 10) + '0';
	write (1, &dev, 1);
	write (1, &mod, 1);
}

void	ft_print_comb2(void)
{
	int	f_nb;
	int	l_nb;

	f_nb = 0;
	while (f_nb <= 98)
	{
		l_nb = f_nb + 1;
		while (l_nb <= 99)
		{
			ft_comb2(f_nb, l_nb);
			if (f_nb != 98)
				write (1, ", ", 2);
			l_nb++;
		}
		f_nb++;
	}
}
