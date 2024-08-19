/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:52:35 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/28 15:12:35 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_types(char c, va_list arg, int n, int *i)
{
	if (c == 'c')
		n += type_is_char((char)va_arg(arg, int));
	else if (c == 's')
		n += type_is_string(va_arg(arg, char *));
	else if (c == 'p')
		n += type_is_pointer(va_arg(arg, void *));
	else if (c == 'i' || c == 'd')
		n += type_is_int(va_arg(arg, int));
	else if (c == 'u')
		n += type_is_unsigned_decimal(va_arg(arg, unsigned long));
	else if (c == 'x')
		n += type_is_lower_hexadecimal(va_arg(arg, unsigned long));
	else if (c == 'X')
		n += type_is_upper_hexadecimal(va_arg(arg, unsigned long));
	else if (c == '%')
		n += type_is_percent();
	i++;
	return (n);
}
