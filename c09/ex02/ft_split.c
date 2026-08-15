/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmelamr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 02:30:49 by ahmelamr          #+#    #+#             */
/*   Updated: 2026/08/03 15:18:31 by ahmelamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (count);
}

int	ft_word_len(char *str, char *charset, int *pos)
{
	int	len;

	len = 0;
	while (str[(*pos) + len] && !is_sep(str[(*pos) + len], charset))
		len++;
	return (len);
}

char	*ft_insert_word(char *str, char *charset, int *pos)
{
	char	*res;
	int		word_len;
	int		i;

	word_len = ft_word_len(str, charset, pos);
	res = malloc (sizeof (char) * (word_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[(*pos) + i] && !is_sep(str[(*pos) + i], charset))
	{
		res[i] = str[(*pos) + i];
		i++;
	}
	*pos += word_len;
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		count_words;
	int		i;
	int		pos;

	count_words = ft_count_words(str, charset);
	res = malloc (sizeof(char *) * (count_words + 1));
	if (!res)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < count_words)
	{
		while (str[pos] && (is_sep(str[pos], charset)))
			pos++;
		res[i] = ft_insert_word(str, charset, &pos);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
/*
int	main(void)
{
	char	str[] = "sohayb-psy\tgg\nWW";
	char	charset[] = " -\t\n";
	char	**res = ft_split(str, charset);
	int i = 0;
	while (res[i])
	{
		printf ("%s\n", res[i]);
		i++;
	}
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
