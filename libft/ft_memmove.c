/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:59:18 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 17:06:03 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src >= dest)
		return (ft_memcpy(dest, src, n));
	else
		while (n > 0)
		{
			n--;
			*(char*)(dest + (n)) = *(char*)(src + (n));
		}
	return (dest);
}
