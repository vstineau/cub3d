/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:24:54 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/17 10:21:23 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	leni(long int n)
{
	long int	c;
	long int	j;
	long int	nb;

	j = 1;
	c = n;
	nb = n;
	if (nb < 0)
		c *= -1;
	while (c >= 10)
	{
		c = c / 10;
		j++;
	}
	if (nb < 0)
		j++;
	return (j);
}

static char	*zero(char *dest)
{
	dest[0] = '0';
	return (dest);
}

char	*ft_itoa(int n)
{
	int			l;
	long int	nb;
	char		*dest;

	nb = n;
	l = leni(nb);
	dest = malloc(sizeof(char) * (l + 1));
	if (!dest)
		return (NULL);
	dest[l--] = '\0';
	if (nb == 0)
		return (zero(dest));
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		dest[l--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (dest);
}
/*	
#include <stdio.h>
int main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-4555));
	printf("%s\n", ft_itoa(-2));
}*/
