NAME	=	so_long

SRCS	=	./srcs/check_parsing.c\
			./srcs/free.c\
			./srcs/init_texture.c\
			./srcs/init.c\
			./srcs/mlx_functions.c\
			./srcs/parsing.c\
			./srcs/renderer.c\
			./srcs/so_long.c\
			./srcs/handle_key.c\
			./lib/libft/ft_bzero.c\
			./lib/libft/ft_calloc.c\
			./lib/libft/ft_ischarset.c\
			./lib/libft/ft_is_not_char.c\
			./lib/libft/ft_itoa.c\
			./lib/libft/ft_memcpy.c\
			./lib/libft/ft_memmove.c\
			./lib/libft/ft_memset.c\
			./lib/libft/ft_newarray.c\
			./lib/libft/ft_strcat.c\
			./lib/libft/ft_strchr.c\
			./lib/libft/ft_strlen.c\
			./tools/get_next_line.c

SRCSBNS	=	./srcs/check_parsing.c\
			./srcs/free.c\
			./srcs/init_texture.c\
			./srcs/init.c\
			./srcs/mlx_functions.c\
			./srcs/parsing.c\
			./srcs/renderer.c\
			./src_bonus/so_long_bonus.c\
			./src_bonus/handle_key_bonus.c\
			./lib/libft/ft_bzero.c\
			./lib/libft/ft_calloc.c\
			./lib/libft/ft_ischarset.c\
			./lib/libft/ft_is_not_char.c\
			./lib/libft/ft_itoa.c\
			./lib/libft/ft_memcpy.c\
			./lib/libft/ft_memmove.c\
			./lib/libft/ft_memset.c\
			./lib/libft/ft_newarray.c\
			./lib/libft/ft_strcat.c\
			./lib/libft/ft_strchr.c\
			./lib/libft/ft_strlen.c\
			./tools/get_next_line.c

CC		=	gcc

CFLAGS		=	-Werror -Wextra -Wall

LIX_LIB		=	-lm -lX11 -lXext -lz

LIX_MLX		=	./lib/minilibx-linux/libmlx_Linux.a

DEL			=	rm -f

OBJ 		=	$(addsuffix .o, $(basename $(SRCS)))

OBJBNS 		=	$(addsuffix .o, $(basename $(SRCSBNS)))

%.o: %.c
				$(CC) -c -o $@ $< $(CFLAGS)

all:			$(NAME)

$(NAME):$(OBJ)
				${CC} -o ${NAME} ${OBJ} ${LIX_MLX} ${LIX_LIB} ${CFLAGS}

bonus:${OBJBNS}
				${CC} -o ${NAME} ${OBJBNS} ${LIX_MLX} ${LIX_LIB} ${CFLAGS}

clean:
				${DEL} ${OBJ} ${OBJBNS}

fclean:			clean
				${DEL} ${NAME}

re:				clean all

re_bonus:		clean bonus

.PHONY: 		clean re bonus re_bonus fclean all