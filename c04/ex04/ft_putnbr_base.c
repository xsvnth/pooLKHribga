/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:46:19 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/07/28 14:25:03 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_check(char *str)
{
	int	i;
	int	freq[256];

	if (ft_strlen(str) < 2)
		return (0);
	i = 0;
	while (i < 256)
		freq[i++] = 0;
	i = 0;
	while (str[i])
	{
		freq[(unsigned char)str[i]]++;
		if (freq[(unsigned char)str[i]] > 1)
			return (0);
		i++;
	}
	if (freq['-'] > 0 || freq['+'] > 0)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		base_len;

	if (!ft_check(base))
		return ;
	base_len = ft_strlen(base);
	nb = (long)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= base_len)
	{
		ft_putnbr_base((int)(nb / base_len), base);
		nb %= base_len;
	}
	write (1, &base[nb % base_len], 1);
}
