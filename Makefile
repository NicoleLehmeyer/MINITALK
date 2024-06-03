.PHONY: all clean fclean re

SERVER = server
CLIENT = client

SERVER_SOURCE = server.c
CLIENT_SOURCE = client.c

LIBFT_ARCHIVE = LIBFT/libft.a

FLAGS = -Wall -Wextra -Werror

SERVER_OBJECT = $(SERVER_SOURCE:%.c=%.o)
CLIENT_OBJECT = $(CLIENT_SOURCE:%.c=%.o)

all: $(LIBFT_ARCHIVE) $(SERVER) $(CLIENT)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFT_ARCHIVE):
	make -s -C LIBFT

$(SERVER): $(LIBFT_ARCHIVE) $(SERVER_OBJECT)
	cc $(FLAGS) -o $(SERVER) $(SERVER_OBJECT) $(LIBFT_ARCHIVE)

$(CLIENT): $(LIBFT_ARCHIVE) $(CLIENT_OBJECT)
	cc $(FLAGS) -o $(CLIENT) $(CLIENT_OBJECT) $(LIBFT_ARCHIVE)

clean:
	rm -f $(SERVER_OBJECT) $(CLIENT_OBJECT)
	make fclean -s -C LIBFT

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -s -C LIBFT

re: fclean all