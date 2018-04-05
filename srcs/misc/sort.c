/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:06:50 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 16:28:37 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

int		ft_sort_tab(char **tab, int size, int (*f)(const char*, const char*))
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < size)
	{
		i = j - 1;
		tmp = tab[j];
		while (i >= 0 && f(tab[i], tmp) > 0)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = tmp;
		j++;
	}
	return (1);
}

static t_file	*sortTime(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->time < lst->next->time))
		lst = lst_swap(lst, lst->next);
	else if (lst->next && lst->time == lst->next->time)
		if (lst->next && (lst->ntime < lst->next->ntime))
			lst = lst_swap(lst, lst->next);
	lst->next = sortTime(lst->next);
	if (lst->next && (lst->time < lst->next->time))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = sortTime(lst->next);
	}
	else if (lst->next && lst->time == lst->next->time)
	{
		if (lst->next && (lst->ntime < lst->next->ntime))
		{
			lst = lst_swap(lst, lst->next);
			lst->next = sortTime(lst->next);
		}
	}
	return (lst);
}

static t_file	*sortSize(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->size < lst->next->size))
		lst = lst_swap(lst, lst->next);
	lst->next = sortSize(lst->next);
	if (lst->next && (lst->size < lst->next->size))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = sortSize(lst->next);
	}
	return (lst);
}

void		sort_list(t_file **lst, char *flags)
{
	MergeSort(lst);
	if (LS_T)
		*lst = sortTime(*lst);
	if (LS_S)
		*lst = sortSize(*lst);
	if (LS_R)
		*lst = sortReverse(*lst);
}
