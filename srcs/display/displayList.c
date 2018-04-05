/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayList.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 03:09:33 by angavrel          #+#    #+#             */
/*   Updated: 2018/04/05 19:27:27 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

int			displayList(t_file **lst, char *flags)
{
	sort_list(lst, flags);
	if (!(LS_L))
		displayBasic(flags, *lst);
	else
		displayLong(flags, *lst);
	return (1);
}
