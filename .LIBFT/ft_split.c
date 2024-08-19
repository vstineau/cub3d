/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:43:42 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/26 12:00:43 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			l++;
		while (s[i] != c && s[i])
			i++;
	}
	return (l);
}

static	int	fill_words(char const *s, char c, char **split, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && k < count)
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		split[k] = ft_calloc((j - i + 1), (sizeof(char)));
		if (!split[k])
			return (0);
		j = 0;
		while (s[i] != c && s[i])
			split[k][j++] = s[i++];
		k++;
	}
	return (1);
}

static void	free_all(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	split = ft_calloc((count + 1), (sizeof(char *)));
	if (split == 0)
		return (NULL);
	if (!(fill_words(s, c, split, count)))
	{
		free_all(split, count);
		return (NULL);
	}
	return (split);
}
/*
#include <stdio.h>
int main()
{
	size_t	i = 0;
	char test []= " aa bb b ";
	char **tab;

	tab = ft_split(test, ' ');
	while (i < count_words(test, ' '))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_all(tab, count_words(test, ' '));
}*/
