/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:02:49 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/07/16 13:14:45 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{	
	int	left;
	int	right;
	int	swap;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		swap = tab[left];
		tab[left] = tab[right];
		tab[right] = swap;
		left++;
		right--;
	}
}
