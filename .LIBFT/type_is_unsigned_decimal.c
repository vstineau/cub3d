/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is_unsigned_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:05:04 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/28 14:55:48 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_is_unsigned_decimal(unsigned int u)
{
	ft_putnbr_base(u, "0123456789");
	return (ft_ulen(u));
}
