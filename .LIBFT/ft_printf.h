/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:59:40 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/01 14:13:38 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		type_is_char(char c);
int		type_is_string(char *s);
int		type_is_pointer(void *p);
int		type_is_int(int i);
int		type_is_unsigned_decimal(unsigned int u);
int		type_is_lower_hexadecimal(unsigned int x);
int		type_is_upper_hexadecimal(unsigned int X);
int		type_is_percent(void);
int		ft_strleni(char *s);
int		ft_hexalen(unsigned long h);
int		ft_intlen(int i);
int		ft_ulen(unsigned long i);
void	ft_putnbr_base(unsigned long nb, char *base);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		print_types(char c, va_list arg, int n, int *i);
int		is_type(char c);

#endif
