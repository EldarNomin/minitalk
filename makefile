NAME1 = server
NAME2 = client

CFLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): server.c utils.c
	gcc $(CGLAGS) server.c utils.c -o $(NAME1)

$(NAME2): client.c utils.c
	gcc $(CFLAGS) client.c utils.c -o $(NAME2)

clean:
	rm -rf client.o server.o

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all
.PHONY: all clean fclean re