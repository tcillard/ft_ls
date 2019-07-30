/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:02 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/26 12:12:51 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *search, const char *find, size_t n)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (*find == '\0')
		return ((char*)search);
	if (ft_strlen(search) < ft_strlen(find) || *search == '\0')
		return (NULL);
	while (*search && ++len <= n && *find)
	{
		i = 0;
		while (find[i] != *search && *search && len++ <= n)
			search++;
		while (find[i] == search[i] && len++ <= n && find[i] && search[i])
			i++;
		if (find[i] == '\0')
			return ((char*)search);
		else if (*search)
		{
			search++;
			len = len - i;
		}
	}
	return (NULL);
}
