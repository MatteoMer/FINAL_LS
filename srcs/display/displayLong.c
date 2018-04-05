/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayLong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:16:55 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 20:21:59 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	displayLong(char *flags, t_file *files)
{
	t_file	*file;
	t_size	size;

	file = files;
	size = get_size(flags, files);
	displayTotal(files);
	while (file)
	{
		if (!(!LS_A && file->name[0] == '.'))
			showlongfile(file, size, flags);
		file = file->next;
	}
}

static void		showchmod(int mode, char path[PATH_MAX])
{
	char	chmod[11];
	chmod[0] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[1] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[2] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[3] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[4] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[5] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[6] = (S_IROTH & mode) ? 'r' : '-';
	chmod[7] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[8] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[9] = get_file_acl(path);
	chmod[10] = '\0';
	if (S_ISUID & mode)
		chmod[2] = chmod[2] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		chmod[5] = chmod[5] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		chmod[8] = chmod[8] == '-' ? 'T' : 't';
	ft_putstr(chmod);
}

void	showperm(t_file *file)
{
	ft_putchar((S_ISFIFO(file->mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(file->mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(file->mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(file->mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(file->mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(file->mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(file->mode)) ? 's' : '\0');
	showchmod(file->mode, file->full_path);
	ft_putstr(" ");
}

static void	displayLink(t_file *file)
{
	char	buf[PATH_MAX + 1];

	readlink(file->full_path, buf, PATH_MAX);
	ft_putstr(" -> ");
	ft_putendl(buf);
}

void	showlongfile(t_file *file, t_size size, char *flags)
{
	showperm(file);
	intdisplay(file->st_nlink, size.linkspace);
	if (getpwuid(file->st_uid))
		strdisplay(getpwuid(file->st_uid)->pw_name, size.userspace);
	else
		intdisplay(file->st_uid, size.userspace);
	if (getgrgid(file->st_gid))
		strdisplay(getgrgid(file->st_gid)->gr_name, size.groupspace);
	else
		intdisplay(file->st_uid, size.userspace);
	if (S_ISCHR(file->mode) || S_ISBLK(file->mode))
		displayMajMin(file, size);
	else
		intdisplay(file->size, size.size);
	displayDate(file->time);
	if (LS_G)
		ft_color(file->mode);
	ft_putstr(file->name);
	ft_putstr(C_NONE);
	if (S_ISLNK(file->mode))
		displayLink(file);
	else
		ft_putendl("");
}
