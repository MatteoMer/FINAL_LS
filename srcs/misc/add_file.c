/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:53:44 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:27:27 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

static t_file	*new_file(char path[PATH_MAX], char *name, t_stat *stat)
{
	t_file	*new;

	if (!(new = (t_file*)ft_memalloc(sizeof(t_file)))
	|| (!(new->name = ft_strdup(name))))
		error(NULL, 2);
	new->next = NULL;
	new->st_nlink = stat->st_nlink;
	new->ntime = stat->st_mtimespec.tv_nsec;
	new->mode = stat->st_mode;
	new->st_blocks = stat->st_blocks;
	new->size = stat->st_size;
	new->st_rdev = stat->st_rdev;
	new->time = stat->st_mtimespec.tv_sec;
	new->st_uid = stat->st_uid;
	new->st_gid = stat->st_gid;
	getpath(path, name, new->full_path);
	return (new);
}

int		add_file(char path[PATH_MAX], char *name, t_file **lst)
{
	char	fullPath[PATH_MAX];
	t_stat	stat;

	if (!(getpath(path, name, fullPath)))
	{
		error(name, 0);
		return (-1);
	}
	if (lstat(fullPath, &stat) == -1)
		return (-1);
	if (!*lst)
		*lst = new_file(path, name, &stat);
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = new_file(path, name, &stat);
	}
	return (1);
}
