/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:32:36 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:27:38 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	get_size_errorhandling(t_size *size, t_file *cur)
{
	if (getpwuid(cur->st_uid))
		size->userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
				  > size->userspace ? (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
				  : size->userspace;
	else
		size->userspace = (int)ft_strlen(ft_itoa(cur->st_uid)) \
				  > size->userspace ? (int)ft_strlen(ft_itoa(cur->st_uid)) \
				  : size->userspace;
	if (getgrgid(cur->st_gid))
		size->groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
				   > size->groupspace ? \
				   (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) : size->groupspace;
	else
		size->groupspace = nblen(cur->st_gid) \
				   > size->groupspace ? nblen(cur->st_gid) \
				   : size->groupspace;
}

void	get_size_quick(t_size *size, t_file *cur)
{
	size->linkspace = nblen(cur->st_nlink) > \
			  size->linkspace ? nblen(cur->st_nlink) \
			  : size->linkspace;
	size->maj = nblen(major(cur->st_rdev)) > size->maj \
		? nblen(major(cur->st_rdev)) : size->maj;
	size->min = nblen(minor(cur->st_rdev)) > size->min ? \
		nblen(minor(cur->st_rdev)) : size->min;

	size->size = nblen(cur->size) > size->size ? \
		     nblen(cur->size) : size->size;
	size->total += cur->st_blocks;
}

t_size	get_size(char *flags, t_file *files)
{
	t_file	*cur;
	t_size	size;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	cur = files;
	while (cur)
	{
		(void)flags;
		if (!(!LS_A && cur->name[0] == '.'))
		{
			get_size_quick(&size, cur);
			get_size_errorhandling(&size, cur);
		}
		cur = cur->next;
	}
	return (size);
}

