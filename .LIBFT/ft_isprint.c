/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:43:53 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/06 16:51:49 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_isprint('s'));
	printf("%d\n", ft_isprint('5'));
	printf("%d\n", ft_isprint('\0'));
}*/
