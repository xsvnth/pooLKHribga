/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:56:58 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/07/28 00:12:15 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	strs_len;
	int	sep_len;
	int	i;

	strs_len = 0;
	i = 0;
	while (i < size)
	{
		strs_len += ft_strlen(strs[i]);
		i++;
	}
	sep_len = ft_strlen(sep) * (size - 1);
	total_len = (strs_len + sep_len);
	total_len += 1;
	return (total_len);
}

char	*ft_insert(int size, char **strs, char *sep, char *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			*(ptr)++ = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				*(ptr)++ = sep[j++];
		}
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*ptr;
	int		total_len;

	if (size == 0)
	{
		res = malloc (sizeof(char));
		if (!res)
			return (res);
		res[0] = '\0';
		return (res);
	}
	total_len = ft_total_len(size, strs, sep);
	res = malloc (sizeof(char) * total_len);
	if (!res)
		return (NULL);
	ptr = res;
	ptr = ft_insert(size, strs, sep, ptr);
	*ptr = '\0';
	return (res);
}
