/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:00:50 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 17:05:24 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, const int c, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = s;
	i = 0;
	while (i < n)
	{
		*cpy = (unsigned char)c;
		i++;
		cpy++;
	}
	return (s);
}
