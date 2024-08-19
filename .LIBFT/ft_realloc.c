/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:27:18 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/26 11:58:38 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t old_length, size_t new_length)
{
	void	*new_ptr;

	new_ptr = ft_calloc(new_length, 1);
	if (new_ptr == NULL)
		return (NULL);
	if (old == NULL)
		return (new_ptr);
	ft_memcpy(new_ptr, old, old_length);
	free(old);
	return (new_ptr);
}
