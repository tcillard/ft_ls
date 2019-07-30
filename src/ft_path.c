/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:41:55 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 22:08:53 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_creat_path(char *path, const char *new, t_stock **st)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!((*st)->path = malloc((ft_strlen(path) + ft_strlen(new)) + 2)))
		return (0);
	while (path[i])
		(*st)->path[j++] = path[i++];
	if ((*st)->path[j - 1] != '/')
		(*st)->path[j++] = '/';
	i = 0;
	while (new[i])
		(*st)->path[j++] = new[i++];
	(*st)->path[j] = '\0';
	return (1);
}

void	ft_print_total(t_stock *st, t_option opt)
{
	char	*total;

	total = ft_itoa(st->total);
	if (!(opt.argna) && !(opt.flags & TYPE_1)
			&& (*(st->name) != '.' || (opt.flags & TYPE_A)))
	{
		ft_putstr("total ");
		ft_putstr(total);
		ft_putchar('\n');
	}
	free(total);
}
