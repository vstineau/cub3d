/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:35:08 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/06 16:52:20 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_isascii('f'));
	printf("%d\n", ft_isascii('\0'));
	printf("%d\n", ft_isascii('L'));
}*/
