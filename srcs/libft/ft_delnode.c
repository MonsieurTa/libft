/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamta <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 23:20:56 by williamta         #+#    #+#             */
/*   Updated: 2019/03/20 19:50:51 by williamta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_delnode(t_list_info *list, t_list *node)
{
	if (node == list->head && list->tail != NULL)
	{
		list->head = node->next;
		list->head->prev = NULL;
	}
	else if (node == list->tail && list->head != NULL)
	{
		list->tail = node->prev;
		list->tail->next = NULL;
	}
	else if (list->head != NULL && list->tail != NULL)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else
		ft_bzero(list, sizeof(t_list_info));
	free(node->content);
	free(node);
}
