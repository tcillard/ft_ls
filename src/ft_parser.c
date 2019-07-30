/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:32:36 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 17:04:37 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_opt_init(t_option *opt)
{
	(*opt).flags = 0;
	(*opt).path = NULL;
	(*opt).name = NULL;
	(*opt).argpa = 0;
	(*opt).argna = 0;
}

int		ft_flags(t_option *opt, char c)
{
	if (c == 'l' && (((*opt).flags & TYPE_L) == 0))
		(*opt).flags = (*opt).flags + TYPE_L;
	if (c == 'l' && (((*opt).flags & TYPE_1)))
		(*opt).flags = (*opt).flags - TYPE_1;
	else if (c == 'R' && (((*opt).flags & TYPE_GR) == 0))
		(*opt).flags = (*opt).flags + TYPE_GR;
	else if (c == 'a' && (((*opt).flags & TYPE_A) == 0))
		(*opt).flags = (*opt).flags + TYPE_A;
	else if (c == 'r' && (((*opt).flags & TYPE_R) == 0))
		(*opt).flags = (*opt).flags + TYPE_R;
	else if (c == 't' && (((*opt).flags & TYPE_T) == 0))
		(*opt).flags = (*opt).flags + TYPE_T;
	else if ((c == '1' && (((*opt).flags & TYPE_1) == 0)))
		(*opt).flags = (*opt).flags + TYPE_1;
	else if ((c == 'G' && (((*opt).flags & TYPE_G) == 0)))
		(*opt).flags = (*opt).flags + TYPE_G;
	else if (c != 'l' && c != 'R' && c != 'a' && c != 'r'
			&& c != 't' && c != '1' && c != 'G')
		return (ft_error_command(c));
	return (1);
}

int		ft_find_flags(t_option *opt, int i, const char **argv)
{
	int		j;

	j = 1;
	while (argv[i][j])
	{
		if (!(ft_flags(opt, argv[i][j])))
			return (0);
		j++;
	}
	return (1);
}

int		ft_parser(int argc, const char **argv, t_option *opt, int *first)
{
	int			i;
	int			ret;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (!(argv[i][1]))
			break ;
		if (argv[i][1] == '-' || argv[i][1] == '\0')
		{
			if ((argv[i][1] == '-') && (argv[i][2] == '-')
					&& !(ft_error_command('-')))
				return (0);
			if (i == 1 && !(argv[2]))
				ft_ls(".", *opt);
			i++;
			break ;
		}
		if (!(ret = ft_find_flags(opt, i, argv)))
			return (0);
		++i;
	}
	(*first) = argc - i;
	return (ft_record_name(opt, argc - i, argv, i));
}
