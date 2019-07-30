/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:17:44 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 15:45:45 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_indent_front(char **str, unsigned int id)
{
	char			*cpy;
	unsigned int	i;
	int				n;
	int				len;

	len = ft_strlen(*str);
	n = 0;
	i = 0;
	cpy = NULL;
	if (!(cpy = malloc(id + 1)))
		exit(0);
	while (id > len + i)
		cpy[i++] = ' ';
	while ((*str)[n])
		cpy[i++] = (*str)[n++];
	cpy[i] = '\0';
	free(*str);
	*str = cpy;
}

void	ft_indent_back(char **str, unsigned int id)
{
	char			*cpy;
	unsigned int	i;
	int				n;

	n = 0;
	i = 0;
	cpy = NULL;
	if (!(cpy = malloc(id + 1)))
		exit(0);
	while ((*str)[n])
		cpy[i++] = (*str)[n++];
	while (id > i)
		cpy[i++] = ' ';
	cpy[i] = '\0';
	free(*str);
	*str = cpy;
}

void	ft_indent_time(char **str, unsigned int id)
{
	char	*cpy;
	int		i;
	int		n;

	n = 0;
	i = 0;
	cpy = NULL;
	if (!(cpy = malloc(id + 1)))
		exit(0);
	while ((*str)[n] != ' ')
		cpy[i++] = (*str)[n++];
	while (id > ft_strlen(*str) + i - 3)
		cpy[i++] = ' ';
	while ((*str)[n])
		cpy[i++] = (*str)[n++];
	cpy[i] = '\0';
	free(*str);
	*str = cpy;
}

void	ft_find_id(t_indent *id, t_stock *st)
{
	while (st)
	{
		if (ft_strlen(st->link) > (*id).link)
			(*id).link = ft_strlen(st->link);
		if (ft_strlen(st->user) > (*id).usr)
			(*id).usr = ft_strlen(st->user);
		if (ft_strlen(st->grp) > (*id).grp)
			(*id).grp = ft_strlen(st->grp);
		if (ft_strlen(st->size) > (*id).size)
			(*id).size = ft_strlen(st->size);
		if (ft_strlen(st->major) + ft_strlen(st->minor) + 2 > (*id).size)
			(*id).size = ft_strlen(st->major) + ft_strlen(st->minor) + 1;
		if (ft_strlen(st->time) > (*id).time)
			(*id).time = ft_strlen(st->time);
		if (ft_strlen(st->minor) > (*id).minor)
			(*id).minor = ft_strlen(st->minor);
		if (ft_strlen(st->major) > (*id).major)
			(*id).major = ft_strlen(st->major);
		st = st->next;
	}
}

void	ft_indent_col(t_stock **st)
{
	t_indent	id;
	t_stock		*cpy;

	cpy = *st;
	ft_init_id(&id);
	ft_find_id(&id, *st);
	while (*st)
	{
		ft_indent_front(&((*st)->link), id.link);
		ft_indent_back(&((*st)->user), id.usr);
		ft_indent_back(&((*st)->grp), id.grp);
		ft_indent_front(&((*st)->size), id.size + id.major);
		ft_indent_time(&((*st)->time), id.time);
		ft_indent_front(&((*st)->major), id.major);
		ft_indent_front(&((*st)->minor), id.minor);
		(*st) = (*st)->next;
	}
	(*st) = cpy;
}
