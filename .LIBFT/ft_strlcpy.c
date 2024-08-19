/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:55:46 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/16 11:23:25 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (ft_strlen(dst));
	if (size > 0)
	{
		while (--size > 0 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[] = "coucou";
	char dest[10];
	memset(dest, 'A', 10);
	printf("%zu\n", ft_strlcpy(dest, src, 0));
	printf("%zu\n", strlcpy(dest, src, 0));
}*/
