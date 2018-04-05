/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:34:56 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 19:24:48 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

int			error(char *s, int error)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*s, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-alRrtSg] [file ...]", 2);
	}
	else if (error == ERRNO || error == MALLOC_ERROR)
		ft_putstr_fd("ft_ls: ", 2);
	if (error == ERRNO)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	exit(EXIT_FAILURE);
}
