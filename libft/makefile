NAME = libft.a

SRC = ft_atoi.c	\
	ft_memchr.c	\
	ft_putnbr.c	\
	ft_strmapi.c	\
	ft_strsub.c	\
	ft_bzero.c	\
	ft_memcmp.c	\
	ft_putnbr_fd.c	\
	ft_strdup.c	\
	ft_strncat.c	\
	ft_strdel.c	\
	ft_strtrim.c	\
	ft_isalnum.c	\
	ft_memcpy.c	\
	ft_putstr.c	\
	ft_strequ.c	\
	ft_strncmp.c	\
	ft_tolower.c	\
	ft_isalpha.c	\
	ft_memdel.c	\
	ft_putstr_fd.c	\
	ft_striter.c	\
	ft_strncpy.c	\
	ft_toupper.c	\
	ft_isascii.c	\
	ft_memmove.c	\
	ft_sqrt.c	\
	ft_striteri.c	\
	ft_strnequ.c	\
	ft_isdigit.c	\
	ft_memset.c	\
	ft_strcat.c	\
	ft_strjoin.c	\
	ft_strnew.c	\
	ft_isprint.c	\
	ft_putchar.c	\
	ft_strchr.c	\
	ft_strlcat.c	\
	ft_strnstr.c	\
	ft_itoa.c	\
	ft_putchar_fd.c	\
	ft_strclr.c	\
	ft_strlen.c	\
	ft_strrchr.c	\
	ft_memalloc.c	\
	ft_putendl.c	\
	ft_strcmp.c	\
	ft_strsplit.c	\
	ft_memccpy.c	\
	ft_putendl_fd.c	\
	ft_strcpy.c	\
	ft_strmap.c	\
	ft_strstr.c	\
	ft_number.c	\
	ft_lstnew.c	\
	ft_lstdelone.c	\
	ft_lstdel.c	\
	ft_lstadd.c	\
	ft_lstiter.c	\
	ft_lstmap.c


OBJECTS = $(SRC:.c=.o)

$(NAME): $(OBJECTS)
	@gcc -Wall -Wextra -Werror -c -I include/ $(SRC)
	@ar rc libft.a $(OBJECTS)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f libft.a

re: fclean all
