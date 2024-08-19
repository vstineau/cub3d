/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:31 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/01 14:28:38 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (!format || (format[0] == '%' && format[i] == '\0'))
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && is_type(format[i + 1]))
		{
			n = print_types(format[i + 1], arg, n, &i);
			i++;
		}
		else
			n += type_is_char(format[i]);
		i++;
	}
	va_end(arg);
	return (n);
}
/*
#include <stdio.h>
int main()
{
	int len = 0;
	int len1 = 0;
	//unsigned long h = 16;
	//unsigned long h1 = 16;
	len = ft_printf("===%=%");
	ft_printf("%d\n", len);
	len1 = printf("===%=%");
	printf("%d\n", len1);
}*/
