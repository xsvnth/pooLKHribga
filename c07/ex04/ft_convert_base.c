/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:30:35 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/08/04 15:25:52 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check(char *base);
int	ft_strlen(char *str);
int	ft_atoi_base(char *nbr, char *base_from);

int	ft_get_nbrlen(long nb, int base_len)
{
	int	str_len;

	str_len = 1;
	if (nb < 0)
	{
		str_len++;
		nb = -nb;
	}
	while (nb >= base_len)
	{
		str_len++;
		nb /= base_len;
	}
	return (str_len);
}

void	ft_insert(char *res, int res_len, long nb, char *base)
{
	int	i;
	int	mod;
	int	base_len;

	base_len = ft_strlen(base);
	res[res_len] = '\0';
	if (nb == 0)
	{
		res[0] = base[0];
		return ;
	}
	i = res_len - 1;
	while (nb > 0)
	{
		mod = nb % base_len;
		res[i--] = base[mod];
		nb /= base_len;
	}
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*res;
	int		base_len;
	int		res_len;
	int		is_negative;
	long	nb;

	if (!ft_check(base))
		return (NULL);
	base_len = ft_strlen(base);
	nb = (long) nbr;
	res_len = ft_get_nbrlen(nb, base_len);
	is_negative = 0;
	if (nb < 0)
	{
		is_negative = 1;
		nb = -nb;
	}
	res = malloc (sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	ft_insert (res, res_len, nb, base);
	if (is_negative)
		res[0] = '-';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		nb;

	if (!ft_check(base_from) || !ft_check(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	res = ft_itoa_base(nb, base_to);
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char nbr[] = "-2147483648";
	char base_from[] = "0123456789";
	char base_to[] = "01";

	char *res = ft_convert_base(nbr, base_from, base_to);
	printf ("%s\n", res);
	free (res);
}
