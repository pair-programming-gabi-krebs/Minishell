/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:14:29 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/05 23:37:00 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* List add front will add new elements to the front of the list
 * We need to change the next of the new element to keeps the address
 * of the pointer that point to the head of the list. Then the pointer
 * keeps the address of the new element.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	new->prv = NULL;
	*lst = new;
}
