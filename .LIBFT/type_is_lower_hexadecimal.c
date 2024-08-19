/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is_lower_hexadecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:07:41 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/28 14:59:04 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_is_lower_hexadecimal(unsigned int x)
{
	ft_putnbr_base(x, "0123456789abcdef");
	return (ft_hexalen(x));
}
