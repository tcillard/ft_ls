/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:09:19 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 09:56:25 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_error_command(char er)
{
	g_ret = 1;
	write(2, "ls: illegal option -- ", 22);
	write(2, &er, 1);
	write(2, "\nusage: ls [-Ralrt1G] [file ...]\n", 33);
	return (0);
}

void	ft_error_file(const char *path)
{
	write(2, "ls: ", 4);
	write(2, path, ft_strlen(path));
	write(2, ": No such file or directory\n", 29);
}

void	ft_error_fd(const char *path)
{
	int		i;
	int		n;
	char	*cpy;

	g_ret = 1;
	n = 0;
	i = ft_strlen(path);
	if (!(cpy = malloc(sizeof(char) * i + 1)))
		exit(1);
	i--;
	while (path[i] && path[i] != '/')
		i--;
	i++;
	while (path[i])
		cpy[n++] = path[i++];
	cpy[n] = '\0';
	write(2, "ls: ", 5);
	write(2, cpy, ft_strlen(cpy));
	write(2, ": directory causes a cycle\n", 29);
}

void	ft_error_acces(const char *path)
{
	int		i;
	int		n;
	char	*cpy;

	g_ret = 1;
	n = 0;
	i = ft_strlen(path);
	if (!(cpy = malloc(sizeof(char) * i + 1)))
		exit(0);
	i--;
	while (path[i] && path[i] != '/')
		i--;
	i++;
	while (path[i])
		cpy[n++] = path[i++];
	cpy[n] = '\0';
	write(2, "ls: ", 4);
	write(2, cpy, ft_strlen(cpy));
	write(2, ": Permission denied\n", 20);
	free(cpy);
}

void	ft_find_error(const char *path)
{
	g_ret = 1;
	if (errno == EACCES)
		ft_error_acces(path);
	else if (errno == ENOTDIR)
		ft_error_file(path);
	else if (errno == ENOENT)
		ft_error_file(path);
	else if (errno == EBADF)
		ft_error_fd(path);
}
