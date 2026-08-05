/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:48:54 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/19 20:46:01 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_nblen(int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int	len;
	
	len = ft_nblen(n);
	res = (char *)malloc (sizeof(char) * (len + 1));
	if (!res)
		return(0);

	res[len] = '\0';
	len--;
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (n)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (res);
}

void	ft_strcat(char *dest, char *src1, char *src2)
{
	int	i;
	int	current;

	i = 0;
	current = 0;
	while (src1[i])
	{
		dest[current] = src1[i];
		current++;
		i++;
	}
	i = 0;
	while (src2[i])
	{
		dest[current] = src2[i]; 
		current++;
		i++;
	}
	dest[current] = '\0';
}

char    *moment(unsigned int duration)
{
	char	*res;
	char	*stor;
	int		number;

	if (duration >= 2592000)
	{
		number = duration / 2592000;
		if (number == 1)
		{
			res = (char *)malloc(sizeof(char ) * 13);
			ft_strcat(res, "1", " month ago.");
		}
		else
		{
			stor = ft_itoa(number);
			res = (char *)malloc(sizeof(char) * (13 + ft_nblen(number)));
			ft_strcat(res, stor, " months ago.");
			free (stor);
		}
	}
	else if (duration >= 86400)
	{
		number = duration / 86400;
		if (number == 1)
		{
			res = (char *)malloc(sizeof(char ) * 11);
			ft_strcat(res, "1", " day ago.");
		}
		else
		{
			stor = ft_itoa(number);
			res = (char *)malloc(sizeof(char) * (11 + ft_nblen(number)));
			ft_strcat(res, stor, " days ago.");
			free (stor);
		}
	}
	else if (duration >= 3600)
	{
		number = duration / 3600;
		if (number == 1)
		{
			res = (char *)malloc(sizeof(char ) * 12);
			ft_strcat(res, "1", " hour ago.");
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (12 + ft_nblen(number)));
			stor = ft_itoa(number);
			ft_strcat(res, stor, " hours ago.");
			free (stor);
		}
	}
	else if (duration >= 60)
	{
		number = duration / 60;
		if (number == 1)
		{
			res = (char *)malloc(sizeof(char ) * 14);
			ft_strcat(res, "1", " minute ago.");
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (14 + ft_nblen(number)));
			stor = ft_itoa(number);
			ft_strcat(res, stor, " minutes ago.");
			free (stor);
		}
	}
	else
	{
		number = duration;
		if (duration == 1)
		{
			res = (char *)malloc(sizeof(char ) * 14);
			ft_strcat(res, "1", " second ago.");
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (14 + ft_nblen(number)));
			stor = ft_itoa(number);
			ft_strcat(res, stor, " seconds ago.");
			free (stor);
		}

	}
	return (res);
}

int	main(void)
{
	char *res;
	res = moment(233439);
	printf ("%s\n", res);
	free (res);
	return (0);
}
