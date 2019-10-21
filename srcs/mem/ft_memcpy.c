/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 02:31:50 by wta               #+#    #+#             */
/*   Updated: 2019/05/15 23:12:20 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char*)dst;
	source = (char*)src;
	while (n--)
		*dest++ = *source++;
	return (dst);
}
