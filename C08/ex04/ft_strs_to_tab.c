/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 23:40:35 by sech-cha          #+#    #+#             */
/*   Updated: 2026/08/01 15:37:19 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(src);
	dup = malloc (sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			i;

	res = malloc (sizeof(struct s_stock_str) * (ac + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		i++;
	}
	res[i].str = 0;
	return (res);
}
/*
int	main(void)
{
	int ac = 3;
	char *av[] = {"sohayb", "psy", "ggWW"};
	struct s_stock_str *res = ft_strs_to_tab(ac, av);
	printf ("%d  ", res[0].size);
	printf ("%s  ", res[0].str);
	printf ("%s  ", res[0].copy);
	printf ("\n");
	printf ("%d  ", res[1].size);
	printf ("%s  ", res[1].str);
	printf ("%s  ", res[1].copy);
	printf ("\n");
	printf ("%d  ", res[2].size);
	printf ("%s  ", res[2].str);
	printf ("%s  ", res[2].copy);
	printf ("\n");
	int i = 0;
	while (i < ac)
	{
		free(res[i].copy);
		i++;
	}
	free(res);
	return (0);
}
*/
