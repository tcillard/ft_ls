/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:11:58 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 17:14:47 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	int		equal;

	count = 0;
	equal = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			count = 0;
			equal = 1;
		}
		s++;
		count++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	while (count != 0)
	{
		s--;
		count--;
	}
	return (equal == 1 ? (char*)s : 0);
}
