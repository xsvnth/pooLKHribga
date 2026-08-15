/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:03:54 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/08/05 11:16:53 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	order;
	int	i;

	if (length <= 1)
		return (1);
	if (tab[0] < tab[1])
		order = 1;
	else
		order = 0;
	i = 0;
	while (i < length - 1)
	{
		if (order == 1 && f(tab[i], tab[i + 1]) > 0)
			return (0);
		else if (order == 0 && f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}
