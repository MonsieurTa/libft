/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:31:42 by wta               #+#    #+#             */
/*   Updated: 2020/02/28 10:57:22 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "libft.h"
#include <stdlib.h>

int					g_optind = 1;
int					g_optopt = 0;
int					g_opterr = 1;
char				*g_optarg = 0;

static void	assign_optarg(int argc, char *const argv[],
	char *curr_c, int *nextchar)
{
	if (*(curr_c + 1))
	{
		g_optarg = curr_c + 1;
		g_optind++;
	}
	else if (g_optind + 1 < argc)
	{
		g_optind++;
		g_optarg = argv[g_optind];
	}
	else
		g_optarg = 0;
	g_optind++;
	*nextchar = 1;
}

static int	scan_opt(int argc, char *const argv[], const char *optstring,
										int *nextchar)
{
	char	*optchar;
	char	*curr_opt;
	char	*curr_c;

	optchar = argv[g_optind];
	if (optchar[0] != '-')
		return (0);
	curr_c = &optchar[*nextchar];
	if (!(curr_opt = ft_strchr(optstring, *curr_c)))
		return (0);
	if (ft_strnequ(curr_opt + 1, ":", 1))
		assign_optarg(argc, argv, curr_c, nextchar);
	else if ((size_t)++(*nextchar) >= ft_strlen(optchar))
	{
		g_optind++;
		*nextchar = 1;
	}
	return (*curr_c);
}

static void	print_error(char *const argv[])
{
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putstr_fd(": illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(g_optopt, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

int			ft_getopt(int argc, char *const argv[],
						const char *optstring)
{
	static int	nextchar = 1;
	int			curr_c;

	if (g_optopt || g_optind >= argc
	|| ft_strequ(argv[g_optind], "-") == 1
	|| (ft_strequ(argv[g_optind], "--") == 1 && g_optind++))
		return (-1);
	curr_c = scan_opt(argc, argv, optstring, &nextchar);
	if (!curr_c)
	{
		g_optopt = argv[g_optind][nextchar];
		g_opterr ? print_error(argv) : NULL;
		return ((int)('?'));
	}
	return (curr_c);
}
