/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:50:32 by wta               #+#    #+#             */
/*   Updated: 2019/03/19 20:00:01 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = NULL;
	if ((ptr = (unsigned char*)malloc(size)) != NULL)
	{
		i = -1;
		while (++i < size)
			ptr[i] = 0;
	}
	return ((void*)ptr);
}
