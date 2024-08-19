/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:17:10 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/16 11:17:12 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1 = (const unsigned char *)s;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
