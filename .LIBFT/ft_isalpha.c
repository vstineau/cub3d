/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:48:15 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/06 16:53:41 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n",ft_isalpha('a'));
	printf("%d\n",ft_isalpha('\0'));
	printf("%d\n",ft_isalpha('B'));
	printf("%d\n",ft_isalpha('5'));
}*/
