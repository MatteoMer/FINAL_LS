/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:26:59 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 19:39:38 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

static t_file	*getfolder(char path[PATH_MAX], char *name, char *flags)
{
	t_file		*lst;
	DIR		*folder;
	struct dirent	*file;

	lst = NULL;

	if (!(folder = opendir(path)))
	{
		error(name, 0);
		return (NULL);
	}
	while ((file = readdir(folder)))
		if (file->d_name[0] != '.' || LS_A)
			add_file(path, file->d_name, &lst);
	if (folder)
		closedir(folder);
	return (lst);
}

void	displayRecursive(t_file *lst, char *flags)
{
	if (!(S_IRUSR & lst->mode))
	{
		ft_putstr("ls: ");
		ft_putstr(lst->name);
		ft_putstr(": Permission denied");
		if (lst->next)
			core(lst->next, flags, 0, -1);
		else
			return ;
	}
	else
		core(lst, flags, 0, -1);
}

int		core(t_file *lst, char *flags, int first, int nbArg)
{
	t_file		*tmp;

	tmp = lst;
	if (!(LS_RR) && !first)
		return (1);
	while (tmp)
	{
		if (S_ISDIR(tmp->mode) && (first || (ft_strcmp(tmp->name, ".")
		&& ft_strcmp(tmp->name, ".."))))
		{
			showpath(tmp->full_path, nbArg, &first);
			lst = getfolder(tmp->full_path, tmp->name, flags);
			if (lst)
			{
				displayList(&lst, flags);
				displayRecursive(lst, flags);
				free_lst(&lst);
			}
		}
		else if (!(LS_RR))
			displayList(&lst, flags);
		tmp = tmp->next;
	}
	return (1);
}
