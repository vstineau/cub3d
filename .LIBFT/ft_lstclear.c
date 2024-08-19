/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:49:50 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/21 14:01:36 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*current2;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		current2 = current->next;
		del(current->content);
		free (current);
		current = current2;
	}
	*lst = NULL;
}
