/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayLong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:16:55 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 20:04:11 by matteo           ###   ########.fr       */
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

void	showperm(t_file *file)
{
	ft_putchar((S_ISFIFO(file->mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(file->mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(file->mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(file->mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(file->mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(file->mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(file->mode)) ? 's' : '\0');
	ft_putchar((file->mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((file->mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((file->mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((file->mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((file->mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((file->mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((file->mode & S_IROTH) ? 'r' : '-');
	ft_putchar((file->mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((file->mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
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
