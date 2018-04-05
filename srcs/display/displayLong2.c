/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayLong2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:16:39 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 20:22:46 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

char		get_file_acl(char path[PATH_MAX])
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
} 

void	displayMajMin(t_file *file, t_size size)
{
	int		min;
	int		maj;

	min = nblen(minor(file->st_rdev));
	maj = nblen(major(file->st_rdev));
	while (maj < size.maj--)
		ft_putchar(' ');
	ft_putnbr(major(file->st_rdev));
	ft_putstr(", ");
	while (min < size.min--)
		ft_putchar(' ');
	ft_putnbr(minor(file->st_rdev));
	ft_putchar(' ');
}

void	ft_color(mode_t mode)
{
	S_ISBLK(mode) ? ft_putstr(C_RED) : NULL;
	S_ISCHR(mode) ? ft_putstr(C_BLUE) : NULL;
	S_ISDIR(mode) ? ft_putstr(C_CYAN) : NULL;
	S_ISFIFO(mode) ? ft_putstr(C_BROWN) : NULL;
	S_ISREG(mode) ? ft_putstr(C_NONE) : NULL;
	S_ISLNK(mode) ? ft_putstr(C_GREEN) : NULL;
	S_ISSOCK(mode) ? ft_putstr(C_MAGENTA) : NULL;
}

void	displayBasic(char *flags, t_file *files)
{
	t_file	*cur;

	cur = files;
	while (cur)
	{
		if (!(!LS_A && cur->name[0] == '.'))
		{
			if (LS_G)
				ft_color(cur->mode);
			ft_putendl(cur->name);
			ft_putstr(C_NONE);
		}
		cur = cur->next;
	}
}

void	displayDate(time_t date)
{
	char	*str1;
	char	*str2;
	time_t	actualtime;

	actualtime = time(0);
	str1 = ctime(&date);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		free(str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}
