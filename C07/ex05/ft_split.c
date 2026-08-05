/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:06:45 by sech-cha          #+#    #+#             */
/*   Updated: 2026/07/30 12:44:57 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) && flag == 1)
			flag = 0;
		if (!is_sep(str[i], charset) && flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

int	ft_word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	return (len);
}

char	*ft_copy_word(char *str, char *charset, int *pos)
{
	char	*res;
	int		j;
	int		word_len;

	word_len = 0;
	while (str[*pos] && is_sep(str[*pos], charset))
		(*pos)++;
	word_len = ft_word_len((str + *pos), charset);
	res = malloc(sizeof(char ) * (word_len + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (j < word_len)
	{
		res[j] = str[*pos + j];
		j++;
	}
	res[j] = '\0';
	*pos += word_len;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		count_words;
	int		pos;
	int		i;

	count_words = ft_count_words(str, charset);
	res = malloc(sizeof(char *) * (count_words + 1));
	if (!res)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < count_words)
	{
		res[i] = ft_copy_word(str, charset, &pos);
		i++;
	}
	res[i] = NULL;
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "sohayb psy\ngg-WW";
	char charset[] = " \n-";

	char	**res = ft_split(str, charset);
	int i = 0;
	while (res[i])
	{
		printf ("%s  ", res[i]);
		i++;
	}
	printf ("\n");
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}
*/
