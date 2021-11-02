SRCS		=	free_map.c \
		error.c \
		aff_game.c \
		aff_image.c \
		get_next_line.c \
		check_map.c \
		so_long.c \
		get_next_line_utils.c \
		key_hook.c \
		new_map.c \
		split.c \
		strcat.c \
		check_inside_map.c \
		mouse_hook.c	\

OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)

CC 			= clang
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f
NAME		= so_long
FLAGS		= -lXext -lX11 libmlx.a libmlx_Linux.a

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all
