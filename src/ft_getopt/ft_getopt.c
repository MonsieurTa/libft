/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:49:59 by wta               #+#    #+#             */
/*   Updated: 2020/01/12 18:18:19 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "libft.h"

extern int	g_optind = 1;
extern int	g_optarg = NULL;

static int	*scan_opt(const optchar[], char *optstring, int *nextchar)
{
	char		*curr_opt;
	char		*curr_c;

	curr_c = &optchar[*nextchar];
	if (!(curr_opt = ft_strchr(optstring, *curr_c)))
		return (NULL);

	if (++(*nextchar) > ft_strlen(optchar))
	{
		g_optind++;
		*nextchar = 0;
	}
	return ((int*)curr_c);
}

int		ft_getopt(int argc, char *const argv[], const char *optstring)
{
	static int	nextchar = 0;
	int					*curr_c;

	if (g_optind >= argc || (ft_strequ(argv[g_optind], "--") == 1 && g_optind++))
		return (-1);
	else if (ft_strequ(argv[g_optind], "-") == 1)
		return (-1);
	curr_c = scan_opt(argv[g_optind], optstring, &nextchar);
	if (!curr_c)
		return invalid_optchar(*curr_c);

	return (0);
}
