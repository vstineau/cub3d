/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:49:04 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/17 01:49:29 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_is_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = 0;
		if (base[i] == '-' || base[i] == '+' || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_search_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	sign;

	if (ft_base_is_correct(base) == 0)
		return (0);
	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_search_in_base(str[i], base))
	{
		nb = nb * (int)ft_strlen(base) + ft_search_in_base(str[i], base);
		i++;
	}
	return (nb * sign);
}	

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
			i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
			nb = nb * 10 + (nptr[i] - 48);
			i++;
	}
	return (nb * sign);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi("123"));
	printf("%d\n", ft_atoi("-123"));
	printf("%d\n", ft_atoi("  -123"));
	printf("%d\n", ft_atoi("  +-123"));
	printf("%d\n", ft_atoi("  + 123"));
	printf("%d\n", ft_atoi(" +12 3"));
	printf("%d\n", ft_atoi(" -12l3"));
}*/
