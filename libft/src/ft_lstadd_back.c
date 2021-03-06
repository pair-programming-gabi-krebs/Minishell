/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:07:25 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/05 23:38:22 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Add a new element at the end of the given linked list.
 * First, we need to declare a pointer that keeps the address
 * to pointer to the list. While next pointer continue existing
 * ptr keeps the next address of the list. When ptr reaches the
 * last next, it change the next from NULL to new.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->next = NULL;
		new->prv = ptr;
	}
}
