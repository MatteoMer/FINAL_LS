/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:44:21 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:26:07 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	intdisplay(int nb, int spacemax)
{
	int		n;

	n = spacemax - nblen(nb);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr(nb);
	ft_putstr(" ");
}

void	strdisplay(char *str, int spacemax)
{
	int		n;

	n = spacemax - ft_strlen(str);
	ft_putstr(str);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}
