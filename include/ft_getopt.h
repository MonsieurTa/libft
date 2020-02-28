/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:50:11 by wta               #+#    #+#             */
/*   Updated: 2020/02/28 09:08:18 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

extern char	*g_optarg;
extern int	g_optind;
extern int	g_opterr;
extern int	g_optopt;

int			ft_getopt(int argc, char *const argv[],
						const char *optstring);

#endif
