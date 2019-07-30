/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:57:15 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 16:58:10 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*cpy;
	unsigned const char	*cpy2;

	cpy = s1;
	cpy2 = s2;
	i = 0;
	while (i < n)
	{
		*cpy = *cpy2;
		i++;
		cpy++;
		cpy2++;
	}
	return (s1);
}
