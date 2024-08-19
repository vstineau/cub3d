/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:43 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/07 11:50:02 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int main ()
{
	printf("%c\n", ft_toupper('d'));
	printf("%c\n", ft_toupper('F'));
	printf("%c\n", ft_toupper('5'));
}*/
