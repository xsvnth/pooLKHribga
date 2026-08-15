/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 21:43:16 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/08/03 00:10:37 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);

void	ft_addition(int a, int b)
{
	ft_putnbr(a + b);
	write (1, "\n", 1);
}

void	ft_diffrence(int a, int b)
{
	ft_putnbr(a - b);
	write (1, "\n", 1);
}

void	ft_multiple(int a, int b)
{
	ft_putnbr(a * b);
	write (1, "\n", 1);
}

void	ft_divition(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	ft_putnbr(a / b);
	write (1, "\n", 1);
}

void	ft_modul(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	ft_putnbr(a % b);
	write (1, "\n", 1);
}
