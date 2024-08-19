/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:00:18 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/10 13:19:16 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*s1;

	s1 = s;
	i = 0;
	while (i < n)
	{
		s1[i] = c;
		i++;
	}
	return (s1);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char t[]= "fdkj";
	char t1[]= "fdkj";
	printf("%s\n", (char*)ft_memset(t, '4',3));
	printf("%s\n", (char*)memset(t1, '4', 3));
}*/
