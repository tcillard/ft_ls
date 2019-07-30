/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:07:33 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 17:01:49 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number(int n)
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

void		ft_putnbr(int n)
{
	int		sqrt;
	int		cpy;
	int		nega;
	int		count;

	count = ft_number(n) - 1;
	nega = 1;
	cpy = 0;
	sqrt = ft_sqrt(n);
	if (n < 0)
	{
		ft_putchar('-');
		nega = -1;
	}
	while (count > 0)
	{
		cpy = n / sqrt;
		n = n - (cpy * sqrt);
		ft_putchar((cpy * nega) + '0');
		sqrt = sqrt / 10;
		count--;
	}
	ft_putchar((n * nega) + '0');
}
