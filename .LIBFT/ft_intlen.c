/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:31:08 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/28 15:09:07 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int i)
{
	int		c;
	long	j;

	c = 1;
	j = i;
	if (j < 0)
	{
		c++;
		j *= -1;
	}
	while (j > 9)
	{
		j /= 10;
		c++;
	}
	return (c);
}
/*
#include <stdio.h>
int	main ()
{
	printf("%d\n", ft_intlen(5));
	printf("%d\n", ft_intlen(-12345678));
	printf("%d\n", ft_intlen(12345678));
}*/
