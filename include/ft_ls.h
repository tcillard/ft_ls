/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:13:42 by tcillard          #+#    #+#             */
/*   Updated: 2019/05/13 22:08:40 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define TYPE_G		128
# define TYPE_L1	64
# define TYPE_1		32
# define TYPE_T		16
# define TYPE_R		8
# define TYPE_A		4
# define TYPE_GR	2
# define TYPE_L		1
# define RED		"\x1B[31m"
# define GRN		"\x1B[32m"
# define YELB		"\x1B[43m"
# define BLU		"\x1B[34m"
# define MAG  		"\x1B[35m"
# define CYN		"\x1B[1;36m"
# define WHT		"\x1B[37m"
# define RESET		"\x1B[0m"
# define CYNB		"\x1B[46m"
# define YEL		"\x1B[33m"

# include <errno.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <grp.h>
# include <pwd.h>
# include <string.h>
# include "libft.h"

typedef struct	s_option
{
	short int	flags;
	char		**name;
	char		**path;
	int			argna;
	int			argpa;
}				t_option;

typedef struct	s_stock
{
	mode_t			mode;
	long			sec;
	char			*name;
	char			*law;
	char			*link;
	char			*size;
	char			type;
	char			*time;
	char			*user;
	char			*grp;
	char			link_name[50];
	struct s_stock	*next;
	struct s_stock	*prev;
	char			*path;
	short			opt;
	unsigned long	block;
	unsigned long	total;
	char			*major;
	char			*minor;
}				t_stock;

typedef struct	s_time
{
	int		years;
	char	*month;
	int		day;
	int		hours;
	int		minutes;
}				t_time;

typedef struct	s_indent
{
	unsigned int	link;
	unsigned int	usr;
	unsigned int	grp;
	unsigned int	size;
	unsigned int	time;
	unsigned int	major;
	unsigned int	minor;
}				t_indent;

int				g_ret;

void			ft_spec_law(struct stat sb, char **law);
void			ft_error_fd(const char *path);
void			ft_color(t_stock *st, t_option opt);
void			ft_find_law(struct stat sb, t_stock **st);
char			*ft_sort_time(struct stat t, t_stock **st);
int				ft_parser(int argc, const char **av, t_option *opt, int *first);
int				ft_error_command(char er);
t_stock			*ft_stock(char *path, t_option opt);
void			ft_ls(char *path, t_option opt);
void			ft_error_file(const char *path);
void			ft_sort_lst(t_stock **st, t_option opt);
void			ft_print_l(t_stock *st, t_option opt);
void			ft_print(t_stock *st, t_option opt);
void			ft_opt_init(t_option *st);
void			ft_find_file(t_stock **st, t_option *opt);
int				ft_creat_path(char *path, const char *new, t_stock **st);
int				ft_print_path(const char *path);
void			ft_replace_lst(t_stock **st);
void			ft_sort_reverse(t_stock **st);
void			ft_find_error(const char *path);
int				ft_check_time(t_stock *st, int s1);
int				ft_creat_lst(t_stock **st);
int				ft_record(t_stock **st);
t_stock			*ft_init_lst(t_stock *past_st);
t_stock			*ft_record_lst(char *path, DIR *dirp, t_option opt);
t_stock			*ft_record_lst_opt(t_option opt);
void			ft_init_id(t_indent *id);
void			ft_indent_col(t_stock **st);
void			ft_error_acces(const char *path);
int				ft_record_name(t_option *opt, int size, const char **av, int i);
void			ft_sort_path(t_option *opt);
void			ft_print_total(t_stock *st, t_option opt);

#endif
