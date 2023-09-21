NAME = cub3d

SRCS = 	 cub3d.c cub3d_utils.c gnl/get_next_line.c error.c gnl/get_next_line_utils.c parsing.c \

OBJS = ${SRCS:.c=.o}

# CC		= gcc
CC		= gcc -g -fsanitize=address
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(NAMES): $(OBJS)
	$(CC) $(OBJS) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAMES)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all