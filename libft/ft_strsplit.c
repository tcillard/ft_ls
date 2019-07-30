/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:12:54 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/26 12:06:57 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char const *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (*s != c)
		n++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

static int	ft_wordlen(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**sp;
	int		i;
	int		n;

	n = 0;
	if (s == NULL || !(sp = (char**)malloc(sizeof(char*) * ft_word(s, c) + 1)))
		return (NULL);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		i = 0;
		if (!(sp[n] = (char*)malloc(sizeof(char*) * ft_wordlen(s, c) + 1)))
			return (NULL);
		while (*s != c && *s)
		{
			sp[n][i] = *s;
			++i && ++s;
		}
		sp[n++][i] = '\0';
		while (*s == c)
			s++;
	}
	sp[n] = NULL;
	return (sp);
}
