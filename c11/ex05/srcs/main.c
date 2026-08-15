/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:50:27 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/08/05 12:58:04 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	ft_addition(int a, int b);
void	ft_diffrence(int a, int b);
void	ft_multiple(int a, int b);
void	ft_divition(int a, int b);
void	ft_modul(int a, int b);

int	ft_get_operator(char *opr)
{
	if (opr[0] && opr[1] == '\0')
	{
		if (opr[0] == '+')
			return (0);
		else if (opr[0] == '-')
			return (1);
		else if (opr[0] == '*')
			return (2);
		else if (opr[0] == '/')
			return (3);
		else if (opr[0] == '%')
			return (4);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int		opr;
	void	(*map[5])(int, int);

	if (argc != 4)
		return (0);
	map[0] = ft_addition;
	map[1] = ft_diffrence;
	map[2] = ft_multiple;
	map[3] = ft_divition;
	map[4] = ft_modul;
	opr = ft_get_operator(argv[2]);
	if (opr >= 0 && opr < 5)
		map[opr](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else
		write (1, "0\n", 2);
	return (0);
}
