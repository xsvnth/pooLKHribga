/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:36:45 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/25 20:38:39 by sech-cha         ###   ########.fr       */
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
	char	freq[256];
	int		i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (i < 256)
	{
		freq[i] = 0;
		i++;
	}
	i = 0;
	while (base[i])
	{
		freq[(unsigned char)base[i]]++;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
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
	int	res;
	int	val;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		val = ft_get_val(str[i], base);
		if (val == -1)
			break ;
		res = res * base_len + val;
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
