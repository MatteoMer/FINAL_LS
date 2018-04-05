/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:59:35 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 20:27:55 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

char		*parse_flags(int argc, char **argv, int *nb)
{
	int		i;
	int		j;
	char		*flags_arg;
	char		*freeit;
	char		flags[] = "lRartG-";

	i = 0;
	j = 0;
	if (!(flags_arg = ft_strnew(0)))
		exit(1);
	while (++i < argc && argv[i][0] == '-')
	{
		while (argv[i][++j])
		{
			if (!(ft_strchr(flags, argv[i][j])))
				error(j + argv[i],1);
		}
		j = 0;
		freeit = flags_arg;
		flags_arg = ft_strjoin(flags_arg, ++argv[i]);
		ft_strdel(&freeit);
		*nb += 1;
	}
	return (flags_arg);
}

