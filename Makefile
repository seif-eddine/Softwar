
CC		=	gcc

NAME	=	server

NAME_C	=	client

SRC		=	server_dir/test.c \
			server_dir/cycle.c \
			server_dir/parse.c \
			server_dir/socket.c \
			server_dir/main.c \
			server_dir/publisher.c \
			server_dir/router.c \
			server_dir/setting.c \
			server_dir/player.c \
			server_dir/energyCells.c \
			server_dir/move_command.c \
			server_dir/info_command.c \
			server_dir/other_command.c \
			server_dir/identity_command.c \
			server_dir/zhelper_function.c \
			server_dir/client_management.c

SRC_C		=	client_dir/client.c

OBJS		=	$(SRC:%.c=%.o)

OBJS_C		=	$(SRC_C:%.c=%.o)

RM		=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -lzmq -lczmq -lpthread

all		:	$(NAME_C) $(NAME) 

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
$(NAME_C)	:	$(OBJS_C)
			$(CC) $(OBJS_C) -o $(NAME_C) $(CFLAGS)

clean		:
			$(RM) $(OBJS)
			$(RM) $(OBJS_C)

fclean		:	clean
			$(RM) $(NAME)
			$(RM) $(NAME_C)

.PHONY		:
			all re clean fclean

re		:	fclean all