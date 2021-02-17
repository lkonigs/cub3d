# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 15:26:59 by lkonig            #+#    #+#              #
#    Updated: 2020/10/27 15:27:18 by lkonig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/ft_cub3d.c \
				srcs/ft_error.c \
				srcs/ft_exit.c \
				srcs/ft_init.c \
				srcs/ft_parse.c \
				srcs/ft_parse_text.c \
				srcs/ft_parse_map.c \
				srcs/ft_parse_endmap.c \
				srcs/ft_parse_color.c \
				srcs/ft_parse_res.c \
				srcs/ft_wall_set.c \
				srcs/ft_wall_tools.c \
				srcs/ft_display.c \
				srcs/ft_event.c \
				srcs/ft_event_turn.c \
				srcs/ft_intersection.c \
				srcs/ft_sprite.c \
				srcs/ft_sprite_sort.c \
				srcs/ft_intersection_tools.c \
				srcs/ft_intersection_init.c \
				srcs/ft_check_map.c \
				srcs/ft_check_others.c \
				srcs/ft_sprite_set.c \
				srcs/ft_save.c

OBJS		=	${SRCS:.c=.o}
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
CFLAGS_MLX	=	-lmlx -L ./minilibX/ -lXext -lX11
CFLAGS_TEST	=	-g3 -fsanitize=address
NAME		=	cub3D

$(NAME):	${OBJS}
			$(MAKE) make_libs
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./libft/libft.a ${CFLAGS_MLX} ./minilibX/libmlx.a -lm

make_libs:
			$(MAKE) all -C ./libft/
			$(MAKE) all -C ./minilibX/

all:		$(NAME)

clean:
			$(MAKE) clean -C ./libft/
			$(MAKE) clean -C ./minilibX/
			rm -f ${OBJS}

fclean:		clean
			$(MAKE) fclean -C ./libft/
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclean re test make_libs