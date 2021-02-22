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

SRCS		=	srcs/ft_cub3d_bonus.c \
				srcs/ft_error_bonus.c \
				srcs/ft_exit_bonus.c \
				srcs/ft_init_bonus.c \
				srcs/ft_parse_bonus.c \
				srcs/ft_parse_text_bonus.c \
				srcs/ft_parse_map_bonus.c \
				srcs/ft_parse_endmap_bonus.c \
				srcs/ft_parse_color_bonus.c \
				srcs/ft_parse_res_bonus.c \
				srcs/ft_wall_set_bonus.c \
				srcs/ft_wall_tools_bonus.c \
				srcs/ft_display_bonus.c \
				srcs/ft_event_bonus.c \
				srcs/ft_event_turn_bonus.c \
				srcs/ft_intersection_bonus.c \
				srcs/ft_sprite_bonus.c \
				srcs/ft_sprite_sort_bonus.c \
				srcs/ft_intersection_tools_bonus.c \
				srcs/ft_intersection_init_bonus.c \
				srcs/ft_check_map_bonus.c \
				srcs/ft_check_others_bonus.c \
				srcs/ft_sprite_set_bonus.c \
				srcs/ft_save_bonus.c \
				srcs/ft_bonus_floor_bonus.c \
				srcs/ft_bonus_sky_bonus.c \
				srcs/ft_bonus_dark_bonus.c \
				srcs/ft_bonus_print_bonus.c

OBJS		=	${SRCS:.c=.o}
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
CFLAGS_MLX	=	-lmlx -L ./minilibX/ -lXext -lX11
CFLAGS_TEST	=	-g3 -fsanitize=address
NAME		=	cub3D_bonus

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