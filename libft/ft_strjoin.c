/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:55:48 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 09:43:23 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int s3)
{
	int		len;
	char	*cpy;
	int		i1;
	int		i2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i1 = 0;
	i2 = 0;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(cpy = malloc(sizeof(char*) * len + 1)))
		exit(1);
	while (s1[i1])
		cpy[i1++] = s1[i2++];
	i2 = 0;
	while (s2[i2])
		cpy[i1++] = s2[i2++];
	cpy[i1] = '\0';
	free(s1);
	if (s3 == 1)
		free(s2);
	return (cpy);
}
