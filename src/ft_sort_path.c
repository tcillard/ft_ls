/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 20:36:41 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 17:33:01 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_path_is_sort(t_option opt, int s1, int s2)
{
	int			i;
	struct stat	sb;
	struct stat	sb1;

	i = 0;
	while ((opt.path)[i + 1])
	{
		if ((!s1 && !s2 && ft_strcmp((opt.path)[i], (opt.path)[i + 1]) > 0))
			return (0);
		else if (!s1 && s2 && ft_strcmp((opt.path)[i], (opt.path)[i + 1]) < 0)
			return (0);
		if (s1)
		{
			if (!(lstat((opt.path)[i], &sb)))
				ft_find_error((opt.path)[i]);
			if (!(lstat((opt.path)[i + 1], &sb1)))
				ft_find_error((opt.path)[i + 1]);
		}
		if (s1 && !s2 && (sb.st_mtimespec.tv_sec < sb1.st_mtimespec.tv_sec))
			return (0);
		else if (s1 && s2 && (sb.st_mtimespec.tv_sec > sb1.st_mtimespec.tv_sec))
			return (0);
		i++;
	}
	return (1);
}

void	ft_swap(t_option *opt, int i)
{
	char	*cpy;

	if (!((*opt).path)[i + 1])
		return ;
	cpy = ((*opt).path)[i];
	((*opt).path)[i] = ((*opt).path)[i + 1];
	((*opt).path)[i + 1] = cpy;
}

void	ft_sort_path_ascii(t_option *opt, int s1)
{
	int		i;

	i = 0;
	while ((ft_path_is_sort(*opt, 0, s1)) == 0)
	{
		while (((*opt).path)[i + 1])
		{
			if (s1 == 0
					&& ft_strcmp(((*opt).path)[i], ((*opt).path)[i + 1]) > 0)
				ft_swap(opt, i);
			else if (s1
					&& ft_strcmp(((*opt).path)[i], ((*opt).path)[i + 1]) < 0)
				ft_swap(opt, i);
			i++;
		}
		i = 0;
	}
}

void	ft_sort_path_time(t_option *opt, int s1)
{
	struct stat	sb;
	struct stat	sb1;
	int			i;

	i = 0;
	while ((ft_path_is_sort(*opt, 1, s1)) == 0)
	{
		while (((*opt).path)[i + 1])
		{
			if (!(lstat(((*opt).path)[i], &sb)))
				ft_find_error(((*opt).path)[i]);
			if (!(lstat(((*opt).path)[i + 1], &sb1)))
				ft_find_error(((*opt).path)[i + 1]);
			if (!s1 && (sb1.st_mtimespec.tv_sec > sb.st_mtimespec.tv_sec))
				ft_swap(opt, i);
			else if (s1 && (sb1.st_mtimespec.tv_sec < sb.st_mtimespec.tv_sec))
				ft_swap(opt, i);
			i++;
		}
		i = 0;
	}
}

void	ft_sort_path(t_option *opt)
{
	if ((*opt).flags & TYPE_T)
	{
		if ((*opt).flags & TYPE_R)
			ft_sort_path_time(opt, 1);
		else
			ft_sort_path_time(opt, 0);
	}
	else
	{
		if ((*opt).flags & TYPE_R)
			ft_sort_path_ascii(opt, 1);
		else
			ft_sort_path_ascii(opt, 0);
	}
}
