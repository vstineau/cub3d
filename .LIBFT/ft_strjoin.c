/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:06:39 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/16 11:43:15 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == 0)
		return (NULL);
	ft_bzero(s3, (ft_strlen(s1) + ft_strlen(s2)));
	while (s1[i])
	{
			s3[i] = s1[i];
			i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
/*
int main()
{
	const char s1[]= "ca";
	const char s2[]= "marche";
	char	*s3 = ft_strjoin(s1, s2);
	ft_putstr_fd(s3, 1);
	free (s3);
}*/	
