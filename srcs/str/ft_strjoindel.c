/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:42:21 by wta               #+#    #+#             */
/*   Updated: 2019/03/19 22:45:44 by williamta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoindel(char const *s1, char const *s2)
{
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		new = ft_strcpy(new, s1);
		new = ft_strcat(new, s2);
		ft_strdel((char**)&s1);
		s1 = NULL;
		return (new);
	}
	return (NULL);
}
