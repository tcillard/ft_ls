/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:16:19 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 22:12:08 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	int		start;
	int		end;
	int		n;

	if (s == NULL)
		return (NULL);
	n = 0;
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& s[start] != '\0')
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && start <= end
			&& s[end] != '\0')
		end--;
	if (!(cpy = (char*)malloc(sizeof(char) * (end - start) + 2)))
		return (0);
	while (start + n <= end)
	{
		cpy[n] = s[start + n];
		n++;
	}
	cpy[n] = '\0';
	return (cpy);
}
