/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayTotal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:31:54 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:26:52 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void		displayTotal(t_file *lst)
{
	int	blocks;

	blocks = 0;
	while (lst)
	{
		blocks += lst->st_blocks;
		lst = lst->next;
	}
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putchar('\n');
}
