/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 06:12:19 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 15:56:02 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_lst(t_stock **st)
{
	t_stock		*cpy;

	while ((*st)->prev)
		(*st) = (*st)->prev;
	cpy = NULL;
	while (*st)
	{
		cpy = (*st);
		free((*st)->name);
		free((*st)->law);
		free((*st)->link);
		free((*st)->size);
		free((*st)->time);
		free((*st)->user);
		free((*st)->grp);
		free((*st)->path);
		free((*st)->minor);
		free((*st)->major);
		(*st) = (*st)->next;
		free(cpy);
	}
}

void		ft_count_bl(t_stock **st)
{
	t_stock		*cpy;

	cpy = *st;
	while (cpy)
	{
		(*st)->total = (*st)->total + cpy->block;
		cpy = cpy->next;
	}
}

void		ft_ls_r(t_stock *st, t_option opt)
{
	while (st && (opt.flags & TYPE_GR))
	{
		if ((st->type == 'd') && (((ft_strcmp(st->name, ".") != 0
				&& ft_strcmp(st->name, "..") != 0) && (opt.flags & TYPE_GR)))
				&& (*st->name != '.' || opt.flags & TYPE_A))
		{
			if (ft_print_path(st->path))
				ft_ls(st->path, opt);
		}
		st = st->next;
	}
}

void		ft_ls(char *path, t_option opt)
{
	t_stock		*st;

	if (!(st = ft_stock(path, opt)))
		return ;
	if (st)
		ft_sort_lst(&st, opt);
	if (st && (opt.flags & TYPE_L))
	{
		ft_count_bl(&st);
		ft_print_l(st, opt);
	}
	else if (st)
		ft_print(st, opt);
	ft_ls_r(st, opt);
	if (st)
		ft_free_lst(&st);
}
