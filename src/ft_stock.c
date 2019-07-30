/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:52:40 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 15:47:28 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stock		*ft_init_lst(t_stock *past_st)
{
	t_stock	*st;

	if (!(st = malloc(sizeof(t_stock))))
		exit(1);
	st->name = NULL;
	st->law = NULL;
	st->link = NULL;
	st->size = NULL;
	st->minor = NULL;
	st->major = NULL;
	st->type = 0;
	st->opt = 0;
	st->time = NULL;
	st->next = NULL;
	st->user = NULL;
	st->grp = NULL;
	st->path = NULL;
	st->sec = 0;
	st->block = 0;
	st->total = 0;
	st->mode = 0;
	st->prev = past_st;
	return (st);
}

char		ft_find_type(struct stat sb)
{
	if ((sb.st_mode & S_IFLNK) == S_IFLNK)
		return ('l');
	else if ((sb.st_mode & S_IFSOCK) == S_IFSOCK)
		return ('s');
	else if ((sb.st_mode & S_IFBLK) == S_IFBLK)
		return ('b');
	else if ((sb.st_mode & S_IFCHR) == S_IFCHR)
		return ('c');
	else if ((sb.st_mode & S_IFIFO) == S_IFIFO)
		return ('p');
	else if ((sb.st_mode & S_IFDIR) == S_IFDIR)
		return ('d');
	else if ((sb.st_mode & S_IFREG) == S_IFREG)
		return ('-');
	return (0);
}

int			ft_record(t_stock **st)
{
	struct stat		sb;
	struct passwd	*pwd;
	struct group	*grp;

	if ((lstat((*st)->path, &sb) != 0) || (!(grp = getgrgid(sb.st_gid))))
	{
		ft_find_error((*st)->path);
		return (0);
	}
	(*st)->mode = sb.st_mode;
	(*st)->major = ft_itoa(major(sb.st_rdev));
	(*st)->minor = ft_itoa(minor(sb.st_rdev));
	(*st)->block = sb.st_blocks;
	(*st)->type = ft_find_type(sb);
	(*st)->size = ft_itoa(sb.st_size);
	(*st)->link = ft_itoa((long long int)sb.st_nlink);
	(*st)->time = ft_sort_time(sb, st);
	ft_find_law(sb, st);
	if ((pwd = getpwuid(sb.st_uid)))
		(*st)->user = ft_strdup(pwd->pw_name);
	else
		(*st)->user = (char*)ft_itoa(sb.st_uid);
	(*st)->grp = ft_strdup(grp->gr_name);
	return (1);
}

t_stock		*ft_stock(char *path, t_option opt)
{
	t_stock			*st;
	DIR				*dirp;

	dirp = NULL;
	st = NULL;
	if (opt.argna)
	{
		if (!(st = ft_record_lst_opt(opt)))
			return (NULL);
		return (st);
	}
	dirp = opendir(path);
	if (dirp == NULL)
	{
		ft_find_error(path);
		return (NULL);
	}
	if (!(st = ft_record_lst(path, dirp, opt)))
	{
		closedir(dirp);
		return (NULL);
	}
	closedir(dirp);
	return (st);
}
