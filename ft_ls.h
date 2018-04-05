/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2018/01/24 22:01:31 by matteo            #+#    #+#             */
/*   Updated: 2018/01/25 10:20:42 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LS_A (ft_strchr(flags, 'a'))
# define LS_L (ft_strchr(flags, 'l'))
# define LS_R (ft_strchr(flags, 'r'))
# define LS_T (ft_strchr(flags, 't'))
# define LS_RR (ft_strchr(flags, 'R'))
# define LS_S (ft_strchr(flags, 's'))
# define LS_G (ft_strchr(flags, 'G'))
# define MAJOR(x) (((x) >> 24) & 0xff)
# define MINOR(x) ((x) & 0xffffff)
# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[1;34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[1;36m"
# define C_GRAY         "\033[37m"


# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <errno.h>
# include "libft/libft.h"

enum	{ERRNO, USAGE, MALLOC_ERROR};
typedef struct stat	t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_file
{
	blkcnt_t			st_blocks;
	mode_t				mode;
	nlink_t				st_nlink;
	uid_t				st_uid;
	gid_t				st_gid;
	off_t				size;
	dev_t				st_rdev;
	time_t				time;
	long				ntime;
	char				*name;
	char				full_path[PATH_MAX];
	struct s_file		*next;
	t_list				list;
}						t_file;

typedef struct		s_size
{
	int				total;
	int				size;
	int				groupspace;
	int				userspace;
	int				linkspace;
	int				min;
	int				maj;
}					t_size;

void		sort_list(t_file **lst, char *flags);
void		MergeSort(t_file **lst);
void		displayTotal(t_file *lst);
int		nblen(size_t nb);
int		ft_sort_tab(char **tab, int size, int (*f)(const char*, const char*));
int			error(char *s, int error);
int		add_file(char path[PATH_MAX], char *name, t_file **lst);
int		free_lst(t_file **lst);
int		displayFiles(t_file **lst, char *flags);
char		get_file_acl(char path[PATH_MAX]);
char		*parse_flags(int argc, char **argv, int *nb);
void		showpath(char *path, int nb, int *first);
int		core(t_file *lst, char *flags, int first,int nbArg);
t_file		*init_list(char **names, int argc, int first);
t_file		*lst_swap(t_file *p1, t_file *p2);
t_file		*SortedMerge(t_file *a, t_file *b);
t_file			*sortReverse(t_file *lst);
t_size		*acces_size(void);
void	displayLong(char *flags, t_file *files);
void		displayTotal(t_file *lst);
void	showperm(t_file *file);
void	showlongfile(t_file *file, t_size size, char *flags);
int			displayList(t_file **lst, char *flags);
void	displayMajMin(t_file *file, t_size size);
char		get_file_acl(char path[PATH_MAX]);
void	ft_color(mode_t mode);
void	displayBasic(char *flags, t_file *files);
void	displayDate(time_t date);
t_size	get_size(char *flags, t_file *files);
void	get_size_quick(t_size *size, t_file *cur);
void	get_size_errorhandling(t_size *size, t_file *cur);
void	intdisplay(int nb, int spacemax);
void	strdisplay(char *str, int spacemax);
t_file	*openfolder(char path[PATH_MAX], char *name, char *flags);
int		getpath(char path[PATH_MAX], char *name,
		char fullPath[PATH_MAX]);

#endif
