/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:07:08 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 17:31:44 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_alloc_arg(int n, int n_pa, t_option *opt)
{
	if (n_pa)
	{
		if (!((*opt).path = malloc((sizeof(char*) * n_pa) + 1)))
			exit(1);
		((*opt).path)[n_pa] = NULL;
	}
	if (n)
	{
		if (!((*opt).name = malloc((sizeof(char*) * n) + 1)))
			exit(1);
		((*opt).name)[n] = NULL;
	}
}

void	ft_count_path(t_option *opt, const char **argv, int i)
{
	int		n;
	int		n_pa;
	DIR		*dirp;

	n = 0;
	n_pa = 0;
	while (argv[i])
	{
		errno = 0;
		if ((dirp = opendir(argv[i])))
		{
			n_pa++;
			closedir(dirp);
		}
		else
		{
			if (errno != EACCES)
				n++;
		}
		i++;
	}
	ft_alloc_arg(n, n_pa, opt);
}

void	ft_record_arg(t_option *opt, const char **argv, int i, DIR *dirp)
{
	int		n;
	int		n_pa;

	n = 0;
	n_pa = 0;
	while (argv[i])
	{
		errno = 0;
		if ((dirp = opendir(argv[i])))
		{
			(*opt).argpa = 1;
			((*opt).path)[n_pa++] = ft_strdup(argv[i++]);
			closedir(dirp);
		}
		else
		{
			if (errno == EACCES)
				ft_error_acces(argv[i++]);
			else
			{
				(*opt).argna = 1;
				((*opt).name)[n++] = ft_strdup(argv[i++]);
			}
		}
	}
}

int		ft_record_name(t_option *opt, int size, const char **argv, int i)
{
	DIR		*dirp;

	dirp = NULL;
	if (size == 0)
		return (1);
	ft_count_path(opt, argv, i);
	ft_record_arg(opt, argv, i, dirp);
	return (1);
}
