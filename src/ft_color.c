/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 01:07:02 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 09:56:12 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_color(t_stock *st, t_option opt)
{
	if (opt.flags & TYPE_G)
	{
		if (st->type == 'd')
			ft_putstr(CYN);
		else if (st->type == 'l')
			ft_putstr(MAG);
		else if (st->type == 'c')
		{
			ft_putstr(YELB);
			ft_putstr(BLU);
		}
		else if (st->type == 's')
			ft_putstr(MAG);
		else if (st->type == 'p' || st->type == 'b')
		{
			ft_putstr(CYNB);
			ft_putstr(BLU);
		}
		else if (st->type == '-' && (st->mode & S_IRWXU) == S_IRWXU)
			ft_putstr(RED);
	}
	ft_putstr(st->name);
	ft_putstr(RESET);
}
