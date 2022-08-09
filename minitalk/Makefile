NAME_SERVER = server
NAME_CLIENT = client

FLAGS = -Wall -Werror -Wextra

DIR_LIBFT = libft/
LIBFT = libft/libft.a

HEADER = minitalk.h

MINITALK_CLIENT = client.c utils.c
MINITALK_SERVER = server.c utils.c

SRCS = client.c server.c utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(MINITALK_SERVER)
	@gcc $(FLAGS) $(MINITALK_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "server is ready"

$(NAME_CLIENT): $(LIBFT) $(MINITALK_CLIENT)
	@gcc $(FLAGS) $(MINITALK_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "client is ready"

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

clean:
	$(MAKE) clean -C $(DIR_LIBFT)
	rm -rf $(OBJS)

fclean:
	$(MAKE) fclean -C $(DIR_LIBFT)
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)

bonus: all
	@echo "minitalk with bonuses is ready"

re: fclean all

.PHONY : all re clean fclean bonus