/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:53:34 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/16 10:55:09 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_s;
	char		*s1;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s || len == 0)
		return (ft_strdup (""));
	len_s -= start;
	if (len_s < len)
		len = len_s;
	s1 = malloc(sizeof(char) * (len + 1));
	if (s1 == 0)
		return (NULL);
	ft_bzero(s1, len + 1);
	while (s[start] && i < len)
	{
		s1[i] = s[start];
		start++;
		i++;
	}
	return (s1);
}
/*
#include <stdio.h>
int main()
{
	char const s[]= ". . .ceci.est un. test . . .";
	char *test;

	test = ft_substr(s, 5, 17);
	printf("%s\n", test);
	free(test);
}*/
