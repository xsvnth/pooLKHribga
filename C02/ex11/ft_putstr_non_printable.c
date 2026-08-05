/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:57:11 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/21 14:03:06 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dis_low_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write (1, "\\", 1);
	write (1, &hex[c / 16], 1);
	write (1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] < 32 || (unsigned char)str[i] > 126)
			ft_dis_low_hex((unsigned char)str[i]);
		else
			write (1, &str[i], 1);
		i++;
	}
}
