/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:46:28 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/22 21:12:38 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_len(char *str)
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
	char	freq[256] = {0};
	
	if (ft_str_len(str) < 2 || ft_str_len(str) > 16)
		return (0);
	i = 0;
	while (str[i])
	{
		freq[(unsigned char)str[i]]++;
		i++;
	}
	if (freq['-'] > 0 || freq['+'] > 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (freq[(unsigned char)str[i]] > 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int	base_len;
	int	check;

	base_len = ft_str_len(base);
	check = ft_check(base);
	if (!check)
		return;
	nb = (long)nbr;
	if (nb == 0)
	{
		write (1, &base[0], 1);
		return;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	write (1, &base[nb % base_len], 1);
}

int	main()
{
	ft_putnbr_base(INT_MIN , "0123456789abcdef");
	ft_putnbr_base(INT_MAX, "0123456789abcdef");
}
