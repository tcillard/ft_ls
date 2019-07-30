/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_law.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 03:50:28 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 10:02:57 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_spec_law(struct stat sb, char **law)
{
	if ((sb.st_mode & S_ISVTX) == S_ISVTX)
		(*law)[8] = 't';
	else if ((sb.st_mode & S_ISGID) == S_ISGID)
		(*law)[5] = 's';
}
