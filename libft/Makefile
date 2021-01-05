# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 17:29:53 by lkonig            #+#    #+#              #
#    Updated: 2020/04/29 17:29:53 by lkonig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRCS = 		ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_free.c		\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isalpha.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_len.c		\
			ft_strmapi.c	\
			ft_split.c		\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_free.c		\
			get_next_line.c
OBJS = $(SRCS:.c=.o)
HEADERS =	libft.h

$(NAME): $(OBJS)
	gcc $(FLAGS) -c $(SRCS) $(HEADERS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS) libft.h.gch

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
