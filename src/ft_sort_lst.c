/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:43:27 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 16:07:52 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_replace_lst(t_stock **st)
{
	t_stock		*c;

	c = (*st)->next->next;
	if ((*st)->prev)
		(*st)->prev->next = (*st)->next;
	if ((*st)->next->next)
		(*st)->next->next->prev = (*st);
	(*st)->next->next = (*st);
	(*st)->next->prev = (*st)->prev;
	(*st)->prev = (*st)->next;
	(*st)->next = c;
}

int		ft_lst_is_sort(t_stock *st, int s1, int s2)
{
	while (st->next)
	{
		if ((!s1 && !s2 && ft_strcmp(st->name, st->next->name) > 0))
			return (0);
		else if (!s1 && s2 && ft_strcmp(st->name, st->next->name) < 0)
			return (0);
		else if (s1 && !s2 && ((st->sec < st->next->sec)))
			return (0);
		else if (s1 && s2 && ((st->sec > st->next->sec)))
			return (0);
		st = st->next;
	}
	return (1);
}

void	ft_sort_lst_ascii(t_stock **st, int s1)
{
	while ((ft_lst_is_sort(*st, 0, s1)) == 0)
	{
		while ((*st)->next)
		{
			if (s1 == 0 && ft_strcmp((*st)->name, (*st)->next->name) > 0)
				ft_replace_lst(st);
			else if (s1 && ft_strcmp((*st)->name, (*st)->next->name) < 0)
				ft_replace_lst(st);
			if ((*st)->next)
				(*st) = ((*st)->next);
		}
		while (((*st)->prev))
			(*st) = (*st)->prev;
	}
}

void	ft_sort_lst_time(t_stock **st, int s1)
{
	while ((ft_lst_is_sort(*st, 1, s1)) == 0)
	{
		while ((*st)->next)
		{
			if (!s1 && (((*st)->sec < (*st)->next->sec)))
				ft_replace_lst(st);
			else if (s1 && (((*st)->sec > (*st)->next->sec)))
				ft_replace_lst(st);
			if ((*st)->next)
				(*st) = ((*st)->next);
		}
		while (((*st)->prev))
			(*st) = (*st)->prev;
	}
}

void	ft_sort_lst(t_stock **st, t_option opt)
{
	if (!(*st))
		return ;
	ft_sort_lst_ascii(st, opt.flags & TYPE_R);
	if (opt.flags & TYPE_T)
		ft_sort_lst_time(st, opt.flags & TYPE_R);
}
