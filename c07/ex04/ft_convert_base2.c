/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:26:03 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/07/28 23:55:18 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_check(char *base)
{
	int	freq[256];
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (i < 256)
		freq[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		freq[(unsigned char)base[i]]++;
		if (freq[(unsigned char)base[i]] > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert(char *str, char *base, int base_len)
{
	int	val;
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		val = ft_get_val(str[i], base);
		if (val < 0)
			break ;
		res = (res * base_len) + val;
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	base_len;
	int	i;

	if (!ft_check(base))
		return (0);
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	base_len = ft_strlen(base);
	res = ft_convert(str + i, base, base_len);
	return (res * sign);
}
