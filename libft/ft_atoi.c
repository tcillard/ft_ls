/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:35:32 by tcillard          #+#    #+#             */
/*   Updated: 2019/04/05 16:59:18 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s1)
{
	char	nega;
	int		nb;

	nb = 0;
	nega = '+';
	while ((*s1 == '\t' || *s1 == '\n' || *s1 == '\f'
			|| *s1 == ' ' || *s1 == '\r' || *s1 == '\v') && *s1)
		s1++;
	if (*s1 == '-' || *s1 == '+')
	{
		nega = *s1;
		s1++;
	}
	while (*s1 >= '0' && *s1 <= '9' && *s1)
	{
		nb = nb * 10 + (*s1 - '0');
		s1++;
	}
	return (nega == '-' ? -nb : nb);
}