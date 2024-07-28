.PHONY: all clean fclean re

SERVER = server
CLIENT = client

SERVER_SOURCE = src/server.c
CLIENT_SOURCE = src/client.c

LIBFT_ARCHIVE = include/LIBFT/libft.a

FLAGS = -Wall -Wextra -Werror -Iinclude

SERVER_OBJECT = $(SERVER_SOURCE:src/%.c=obj/%.o)
CLIENT_OBJECT = $(CLIENT_SOURCE:src/%.c=obj/%.o)

all: $(LIBFT_ARCHIVE) $(SERVER) $(CLIENT)

obj/%.o: src/%.c
	mkdir -p obj
	cc $(FLAGS) -c $< -o $@

$(LIBFT_ARCHIVE):
	make -s -C include/LIBFT

$(SERVER): $(LIBFT_ARCHIVE) $(SERVER_OBJECT)
	cc $(FLAGS) -o $(SERVER) $(SERVER_OBJECT) $(LIBFT_ARCHIVE)

$(CLIENT): $(LIBFT_ARCHIVE) $(CLIENT_OBJECT)
	cc $(FLAGS) -o $(CLIENT) $(CLIENT_OBJECT) $(LIBFT_ARCHIVE)

clean:
	rm -rf obj
	make fclean -s -C include/LIBFT

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -s -C include/LIBFT

re: fclean all