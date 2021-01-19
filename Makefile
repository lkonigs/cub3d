SRCS		=	srcs/ft_cub3d.c \
				srcs/ft_error.c \
				srcs/ft_init.c \
				srcs/ft_parse.c \
				srcs/ft_parse_others.c \
				srcs/ft_setwall.c \
				srcs/ft_setwall_tools.c \
				srcs/ft_display.c \
				srcs/ft_event.c \
				srcs/ft_event_turn.c \
				srcs/ft_intersection.c \
				srcs/ft_parse_map.c \
				srcs/ft_sprite.c \
				srcs/ft_sprite_sort.c \
				srcs/ft_intersection_tools.c \
				srcs/ft_intersection_init.c \
				srcs/ft_checkconditions.c \
				srcs/ft_setsprite.c \
				srcs/ft_save.c

OBJS		=	${SRCS:.c=.o}
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
CFLAGS_MLX	=	-lmlx -L ./minilibX/ -lXext -lX11
CFLAGS_TEST	=	-g3 -fsanitize=address
NAME		=	Cub3D

$(NAME):	make_libs test

make_libs:
			$(MAKE) all -C ./libft/

all:		$(NAME)

test:		${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./libft/libft.a ${CFLAGS_MLX} ./minilibX/libmlx.a -lm

clean:
			$(MAKE) clean -C ./libft/
			rm -f ${OBJS}

fclean:		clean
			$(MAKE) fclean -C ./libft/
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclean re test make_libs