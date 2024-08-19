/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:42:32 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/16 13:52:47 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*s2;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (s1[i] && ft_isinset(set, s1[i]) == 1)
		i++;
	while (j > 0 && ft_isinset(set, s1[j - 1]) == 1)
		j--;
	if (i >= j)
		return (ft_strdup(""));
	s2 = (char *)ft_calloc((j - i + 1), sizeof(char));
	if (s2 == 0)
		return (NULL);
	while (i < j)
		s2[k++] = s1[i++];
	s2[k] = '\0';
	return (s2);
}
/*
#include <stdio.h>
int main()
{
	char const s1[]= ". . .ceci.est un. test . . .";
	char const set[]= ". .";
	char *test;

	test = ft_strtrim(s1,set);
	printf("%s\n", test);
	free(test);
}*/
