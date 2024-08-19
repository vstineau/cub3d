/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:43:47 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/15 15:21:22 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	i = 0;
	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	while (i < n)
	{
		if (s1b[i] == s2b[i])
			i++;
		else
			return (s1b[i] - s2b[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int    main(void)
{
    char    str1[] = {-128, 0, 127, 0};
    char    str2[] = {-128, 0, 127, 0};
    printf("memcmp ft : %d\n", ft_memcmp(str1, str2, 0));
    printf("memcmp : %d", memcmp(str1, str2, 0));
    return (0);
}*/
