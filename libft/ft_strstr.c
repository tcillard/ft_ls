/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:14:05 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 17:19:18 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *search, const char *find)
{
	int		i;

	i = 0;
	if (search == find || *find == '\0')
		return ((char*)search);
	if (ft_strlen(search) < ft_strlen(find))
		return (NULL);
	while (*search)
	{
		i = 0;
		while (find[i] != *search && *search)
			search++;
		while (find[i] == search[i] && find[i] && search[i])
			i++;
		if (find[i] == '\0')
			return ((char*)search);
		else if (*search)
			search++;
	}
	return (NULL);
}
