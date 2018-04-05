/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:01:55 by matteo            #+#    #+#             */
/*   Updated: 2018/04/05 19:26:13 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

t_file	*SortedMerge(t_file *a, t_file *b)
{
	t_file		*result;

	if (a == NULL)
		return(b);
	else if (b==NULL)
		return(a);

	if (ft_strcmp(a->name, b->name) < 0)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

static void		frontBackSplit(t_file *tmp, t_file **a, t_file **b)
{
	t_file	*slow;
	t_file	*fast;

	if (!a || !b)
	{
		*a = tmp;
		*b = NULL;
	}
	else
	{
		slow = tmp;
		fast = tmp->next;
		while (!fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*a = tmp;
		*b = slow->next;
		slow->next = NULL;
	}
}
void	MergeSort(t_file **lst)
{
	t_file	*head;
	t_file	*a;
	t_file	*b;

	head = *lst;
	if ((head == NULL) || (head->next == NULL))
		return;
	frontBackSplit(head, &a, &b); 
	MergeSort(&a);
	MergeSort(&b);
	*lst = SortedMerge(a, b);
}

