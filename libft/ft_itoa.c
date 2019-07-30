/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:44:35 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 09:42:12 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_number(long long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(long long int n)
{
	char			*strnb;
	int				i;
	int				test;

	i = ft_number(n);
	test = 1;
	if (n < 0)
		test = 2;
	if (!(strnb = (char*)malloc(sizeof(char) * (i + test))))
		exit(0);
	if (n < 0)
		strnb[0] = '-';
	else
		i--;
	strnb[i + test] = '\0';
	while ((i >= 0 && test == 1) || (test == 2 && i > 0))
	{
		if (test == 1)
			strnb[i] = (n - (n / 10 * 10)) + '0';
		else
			strnb[i] = ((n - (n / 10 * 10)) * -1) + '0';
		n = n / 10;
		i--;
	}
	return (strnb);
}
