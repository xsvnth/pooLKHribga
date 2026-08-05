/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:51:43 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/27 17:04:09 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	len;
	int	i;

	if (max <= min)
		return (NULL);
	len = max - min;
	res = malloc (sizeof(int) * len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
