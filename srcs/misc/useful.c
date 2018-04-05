/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:42:28 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:29:47 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

int		free_lst(t_file **lst)
{
	while (*lst)
	{
		free((*lst)->name);
		free(*lst);
		*lst = (*lst)->next;
	}
	return (1);
}

int		nblen(size_t nb)
{
	int		i;

	i = 1;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

t_file	*lst_swap(t_file *p1, t_file *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

int		getpath(char path[PATH_MAX], char *name,
		char fullPath[PATH_MAX])
{
	int	i;

	i = -1;
	while (path[++i])
		fullPath[i] = path[i];
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
			fullPath[i++] = '/';
	while (*name && i < PATH_MAX)
		fullPath[i++] = *name++;
	if (i < PATH_MAX)
		fullPath[i] = '\0';
	else
		errno = ENAMETOOLONG;
	return ((i < PATH_MAX) ? 1 : 0);
}
