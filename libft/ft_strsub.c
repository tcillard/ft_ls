/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:14:38 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 22:11:27 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*cpy;

	n = 0;
	if (s == NULL || ft_strlen(s) < start)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (n < len)
	{
		cpy[n] = s[start];
		n++;
		start++;
	}
	cpy[n] = '\0';
	return (cpy);
}
