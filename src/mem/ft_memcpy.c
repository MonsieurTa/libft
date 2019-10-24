/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 02:31:50 by wta               #+#    #+#             */
/*   Updated: 2019/10/24 17:32:29 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n >= sizeof(__uint128_t))
	{
		n -= sizeof(__uint128_t);
		*(__uint128_t*)(dst + n) = *(__uint128_t*)(src + n);
	}
	while (n >= sizeof(uint64_t))
	{
		n -= sizeof(uint64_t);
		*(uint64_t*)(dst + n) = *(uint64_t*)(src + n);
	}
	while (n >= sizeof(uint32_t))
	{
		n -= sizeof(uint32_t);
		*(uint32_t*)(dst + n) = *(uint32_t*)(src + n);
	}
	while (n >= sizeof(uint16_t))
	{
		n -= sizeof(uint16_t);
		*(uint16_t*)(dst + n) = *(uint16_t*)(src + n);
	}
	while (n > 0)
	{
		n--;
		*(uint8_t*)(dst + n) = *(uint8_t*)(src + n);
	}
	return (dst);
}
