/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:21:44 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 22:08:33 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_id(t_indent *id)
{
	(*id).link = 0;
	(*id).usr = 0;
	(*id).grp = 0;
	(*id).size = 0;
	(*id).time = 0;
	(*id).major = 0;
	(*id).minor = 0;
}

void	ft_print(t_stock *st, t_option opt)
{
	char	c;

	if (opt.flags & TYPE_1)
		c = '\n';
	else
		c = ' ';
	while (st)
	{
		ft_color(st, opt);
		if (st->next)
			ft_putchar(c);
		st = st->next;
	}
	ft_putchar('\n');
}

void	ft_print_all(t_stock *st, t_option opt)
{
	ft_putchar(st->type);
	ft_putstr(st->law);
	ft_putchar(' ');
	ft_putstr(st->link);
	ft_putchar(' ');
	ft_putstr(st->user);
	ft_putchar(' ');
	ft_putstr(st->grp);
	ft_putchar(' ');
	if (st->type == 'c' || st->type == 'b')
	{
		ft_putstr(st->major);
		ft_putstr(", ");
		ft_putstr(st->minor);
	}
	else
		ft_putstr(st->size);
	ft_putchar(' ');
	ft_putstr(st->time);
	ft_putchar(' ');
	ft_color(st, opt);
}

void	ft_print_l(t_stock *st, t_option opt)
{
	ft_print_total(st, opt);
	ft_indent_col(&st);
	while (st)
	{
		if (!(opt.flags & TYPE_1) && (*(st->name) != '.'
					|| (opt.flags & TYPE_A) || opt.argna))
		{
			ft_print_all(st, opt);
			if (st->type == 'l')
			{
				ft_putstr(" -> ");
				ft_putstr(st->link_name);
			}
		}
		else if ((opt.flags & TYPE_1) && (*(st->name) != '.'
					|| (opt.flags & TYPE_A)))
			ft_putstr(st->name);
		ft_putchar('\n');
		st = st->next;
	}
}

int		ft_print_path(const char *path)
{
	DIR		*dirp;

	if ((dirp = opendir(path)))
	{
		closedir(dirp);
		ft_putchar('\n');
		ft_putstr(path);
		ft_putchar(':');
		ft_putchar('\n');
		return (1);
	}
	else
	{
		ft_find_error(path);
		return (0);
	}
}
