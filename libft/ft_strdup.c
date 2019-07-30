/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:52:22 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 09:43:33 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *c)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = NULL;
	if (!(cpy = (char*)malloc(sizeof(char) * ft_strlen(c) + 1)))
		exit(1);
	while (c[i])
	{
		cpy[i] = c[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
