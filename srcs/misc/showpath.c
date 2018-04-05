/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:07:27 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:28:24 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void		showpath(char *path, int nb, int *first)
{
	if (nb != 1 && nb)
	{
		if (*first == 2)
		{
			*first = 1;
			ft_putstr(path);
			ft_putendl(":");
		}
		else
		{
			ft_putstr("\n");
			ft_putstr(path);
			ft_putendl(":");
		}
	}
}
