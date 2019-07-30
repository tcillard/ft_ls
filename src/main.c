/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:06:53 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 17:01:36 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_del_opt(t_option *opt, int s1)
{
	int		i;

	i = 0;
	if (!(s1))
	{
		while (((*opt).name)[i])
		{
			free(((*opt).name)[i]);
			((*opt).name)[i++] = NULL;
		}
		free((*opt).name);
		(*opt).name = NULL;
		(*opt).argna = 0;
	}
	else
	{
		while (((*opt).path)[i])
		{
			free(((*opt).path)[i]);
			((*opt).path)[i++] = NULL;
		}
		free((*opt).path);
		(*opt).path = NULL;
		(*opt).argpa = 0;
	}
}

void	ft_opt(const char **argv, int argc, t_option opt)
{
	int			i;
	int			first;

	first = 0;
	i = 0;
	if (!(ft_parser(argc, argv, &opt, &first)))
		exit(1);
	if (opt.argna || (opt.flags && !(opt.path)))
		ft_ls(".", opt);
	if (opt.argna)
		ft_del_opt(&opt, 0);
	if (opt.argpa)
		ft_sort_path(&opt);
	while (opt.path && opt.path[i])
	{
		if (first > 1 && (opt.path || (opt.path && opt.name)))
			ft_print_path((char*)opt.path[i]);
		ft_ls((char*)opt.path[i++], opt);
	}
	if (opt.argpa)
		ft_del_opt(&opt, 1);
}

int		main(int argc, const char **argv)
{
	t_option	opt;

	g_ret = 0;
	ft_opt_init(&opt);
	if (argc > 1)
		ft_opt(argv, argc, opt);
	else
		ft_ls(".", opt);
	return (g_ret);
}
