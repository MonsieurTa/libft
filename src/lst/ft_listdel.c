/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 23:23:19 by williamta         #+#    #+#             */
/*   Updated: 2020/01/26 17:34:08 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_listdel(t_list_info *list)
{
	t_list	*node;
	t_list	*tmp;

	node = list->head;
	if (node != NULL)
	{
		list->head = NULL;
		list->tail = NULL;
		while (node != NULL)
		{
			tmp = node;
			node = node->next;
			free(tmp->content);
			free(tmp);
		}
		list->size = 0;
	}
}
