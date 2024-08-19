/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is_upper_hexadecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:11:48 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/28 14:59:23 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_is_upper_hexadecimal(unsigned int X)
{
	ft_putnbr_base(X, "0123456789ABCDEF");
	return (ft_hexalen(X));
}
