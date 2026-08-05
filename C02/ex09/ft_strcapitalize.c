/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 13:17:32 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/18 15:09:04 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cp(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_cp(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z' && flag == 0)
			{
				str[i] -= 32;
				flag = 1;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z' && flag == 1)
				str[i] += 32;
			else
				flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	return (str);
}
