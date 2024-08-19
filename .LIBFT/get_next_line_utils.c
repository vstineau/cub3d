/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:45:13 by vstineau          #+#    #+#             */
/*   Updated: 2024/03/05 13:32:34 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *line)
{
	char	*temp;

	temp = ft_strjoin(buffer, line);
	free(buffer);
	return (temp);
}
