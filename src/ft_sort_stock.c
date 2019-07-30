/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:22:58 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 15:30:27 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_find_law(struct stat sb, t_stock **st)
{
	int		i;

	if (!((*st)->law = malloc(sizeof(char) * 10)))
		exit(1);
	(*st)->law[9] = '\0';
	i = 0;
	while (i <= 8)
	{
		if (((sb.st_mode & S_IRUSR) && i == 0)
				|| ((sb.st_mode & S_IRGRP) && i == 3)
				|| ((sb.st_mode & S_IROTH) && i == 6))
			(*st)->law[i] = 'r';
		else if (((sb.st_mode & S_IWUSR) && i == 1)
				|| ((sb.st_mode & S_IWGRP) && i == 4)
				|| ((sb.st_mode & S_IWOTH) && i == 7))
			(*st)->law[i] = 'w';
		else if (((sb.st_mode & S_IXUSR) && i == 2)
				|| ((sb.st_mode & S_IXGRP) && i == 5)
				|| ((sb.st_mode & S_IXOTH) && i == 8))
			(*st)->law[i] = 'x';
		else
			(*st)->law[i] = '-';
		i++;
	}
	ft_spec_law(sb, &((*st)->law));
}

int		ft_find_time_numbers(char *time, t_time *ti_stock)
{
	int		i;
	int		j;

	j = 0;
	i = 4;
	if (time == NULL)
		return (0);
	while (time[i] && time[i] != ' ')
		((*ti_stock).month)[j++] = time[i++];
	while (time[i] < '0' || time[i] > '9')
		i++;
	while (time[i] >= '0' && time[i] <= '9')
		(*ti_stock).day = ((*ti_stock).day * 10) + (time[i++] - '0');
	i++;
	while (time[i] >= '0' && time[i] <= '9')
		(*ti_stock).hours = ((*ti_stock).hours * 10) + (time[i++] - '0');
	i++;
	while (time[i] >= '0' && time[i] <= '9')
		(*ti_stock).minutes = ((*ti_stock).minutes * 10) + (time[i++] - '0');
	return (1);
}

t_time	ft_registre_time(struct stat sb)
{
	t_time		time_stock;

	time_stock.years = 0;
	time_stock.month = 0;
	time_stock.day = 0;
	time_stock.hours = 0;
	time_stock.minutes = 0;
	if (!(time_stock.month = malloc(sizeof(char) * 4)))
		return (time_stock);
	(time_stock.month)[4] = '\0';
	if (!(ft_find_time_numbers(ctime(&sb.st_mtime), &time_stock)))
	{
		free(time_stock.month);
		time_stock.month = NULL;
		return (time_stock);
	}
	time_stock.years = (sb.st_mtime / 31557600) + 1970;
	return (time_stock);
}

char	*ft_write_time(t_time stock, int s1)
{
	char	*time;

	time = ft_strdup(stock.month);
	free(stock.month);
	stock.month = NULL;
	time = ft_strjoin(time, " ", 0);
	time = ft_strjoin(time, ft_itoa(stock.day), 1);
	if (s1 == 0)
	{
		time = ft_strjoin(time, " ", 0);
		if (stock.hours < 10)
			time = ft_strjoin(time, "0", 0);
		time = ft_strjoin(time, ft_itoa(stock.hours), 1);
		time = ft_strjoin(time, ":", 0);
		if (stock.minutes < 10)
			time = ft_strjoin(time, "0", 0);
		time = ft_strjoin(time, ft_itoa(stock.minutes), 1);
	}
	else
	{
		time = ft_strjoin(time, "  ", 0);
		time = ft_strjoin(time, ft_itoa(stock.years), 1);
	}
	return (time);
}

char	*ft_sort_time(struct stat sb, t_stock **st)
{
	time_t		t;
	long int	diff;
	t_time		time_stock;

	t = time(NULL);
	time_stock = ft_registre_time(sb);
	diff = (t - sb.st_mtime) / 2629800;
	(*st)->sec = sb.st_mtimespec.tv_sec;
	if (diff <= 5 && diff >= -5)
		return (ft_write_time(time_stock, 0));
	else
		return (ft_write_time(time_stock, 1));
	return (NULL);
}
