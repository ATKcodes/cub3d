NAME = cub3d

SRCS = 	 cub3d.c cub3d_utils.c gnl/get_next_line.c error.c gnl/get_next_line_utils.c parsing.c info_gather.c save_param.c save_param2.c open_window.c raycast.c raycast_util.c render.c save_param3.c\

OBJS = ${SRCS:.c=.o}

#CC		= gcc 
 CC		= gcc -g -fsanitize=address
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
#CFLAGS = -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make --silent -C minilibx-linux 2>/dev/null
	$(CC) $(OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# $(NAMES): $(OBJS)
# 	@make --silent -C minilibx-linux 2>/dev/null
# 	$(CC) $(OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all