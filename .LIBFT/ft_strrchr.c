/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:10:13 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/15 15:55:28 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			j = i;
			count++;
		}
		i++;
	}
	if (count > 0)
		return ((char *)s + j);
	else
		return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "tripouille";
	printf("%s\n", ft_strrchr(s, 't'));
	printf("%s\n", strrchr(s, 't'));
}*/
