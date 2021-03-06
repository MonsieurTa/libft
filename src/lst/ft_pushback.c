/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:10:45 by wta               #+#    #+#             */
/*   Updated: 2020/01/26 17:33:23 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pushback(t_list_info *list, t_list *node)
{
	if (node != NULL)
	{
		if (list->head == NULL)
			list->head = node;
		else if (list->tail == NULL)
		{
			list->head->next = node;
			list->tail = node;
			node->prev = list->head;
		}
		else
		{
			node->prev = list->tail;
			list->tail->next = node;
			list->tail = node;
		}
		list->size++;
	}
}
