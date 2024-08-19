/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:37:42 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/01 14:15:57 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nb, char *base)
{
	int	len;

	len = ft_strleni(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= (unsigned long)len)
	{
		ft_putnbr_base(nb / (unsigned long)len, base);
		ft_putnbr_base(nb % (unsigned long)len, base);
	}
	else
		write(1, &base[nb], 1);
}
/*
int main ()
{
	ft_putnbr_base(20, "0123456789abcdef");
}*/
