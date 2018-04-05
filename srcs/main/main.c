/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:36:37 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:27:12 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

t_file		*init_list(char **names, int argc, int first)
{
	t_file	*new;
	int	i;

	new = NULL;
	(argc == 0) ? add_file("", ".", &new) : ft_sort_tab(names, argc,\
	&ft_strcmp);
	i = -1;
	while (++i < argc)
	{
		if (add_file("", names[i], &new) == -1 && first)
			error(names[i], 0);
	}
	return (new);
}

int		main(int argc, char **argv)
{
	int	nb;
	char	*flags;
	t_file	*lst;
	int	no_files;

	nb = 1;
	flags = parse_flags(argc, argv, &nb);
	argv += nb;
	argc -= nb;
	lst = init_list(argv, argc, 1);
	no_files = (!lst ? 1 : 0);
	core(lst, flags, (!no_files? 1 : 2), argc);
	free_lst(&lst);
	exit(EXIT_SUCCESS);
}
