/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 07:22:00 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 22:04:23 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_last(t_stock **st, t_stock **cpy, int ret)
{
	if ((*st)->prev)
		(*st)->prev->next = NULL;
	if (!ret)
		(*cpy) = NULL;
	free(*st);
}

t_stock		*ft_record_lst(char *path, DIR *dirp, t_option opt)
{
	t_stock			*st;
	t_stock			*cpy_st;
	struct dirent	*dp;
	int				ret;

	ret = 0;
	if (!(st = ft_init_lst(NULL)))
		return (NULL);
	cpy_st = st;
	while ((dp = readdir(dirp)) != NULL)
	{
		if (*dp->d_name != '.' || (opt.flags & TYPE_A))
		{
			st->name = ft_strdup(dp->d_name);
			ft_creat_path(path, dp->d_name, &st);
			if (ft_creat_lst(&st))
			{
				ret = 1;
				st = st->next;
			}
		}
	}
	ft_free_last(&st, &cpy_st, ret);
	return (cpy_st);
}

t_stock		*ft_record_lst_opt(t_option opt)
{
	t_stock			*st;
	t_stock			*cpy_st;
	int				i;
	int				ret;

	ret = 0;
	i = -1;
	if (!(st = ft_init_lst(NULL)))
		return (NULL);
	cpy_st = st;
	while (opt.name[++i])
	{
		st->name = ft_strdup(opt.name[i]);
		st->path = ft_strdup(opt.name[i]);
		if (ft_creat_lst(&st))
		{
			ret = 1;
			st = st->next;
		}
	}
	ft_free_last(&st, &cpy_st, ret);
	return (cpy_st);
}

int			ft_creat_lst(t_stock **st)
{
	int		ret;

	ret = 0;
	if (!((*st)->next) && !((*st)->next = ft_init_lst(*st)))
		return (0);
	if (!(ft_record(st)))
	{
		free((*st)->next);
		(*st)->next = NULL;
		return (0);
	}
	if ((*st)->type == 'l')
	{
		if ((ret = readlink((*st)->path, (*st)->link_name, 49)) == -1)
		{
			free((*st)->next);
			(*st)->next = NULL;
			return (0);
		}
		((*st)->link_name)[ret] = '\0';
	}
	return (1);
}
