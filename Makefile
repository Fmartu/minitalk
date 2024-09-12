NAME = server
NAME2 = client

all : ft_printf/libftprintf.a client server

ft_printf/libftprintf.a :
	@make -C ft_printf/

$(NAME2) : client.c ft_printf/libftprintf.a
	cc -Wall -Wextra -Werror client.c ft_printf/libftprintf.a -o $(NAME2) 
	
$(NAME) : server.c ft_printf/libftprintf.a
	cc -Wall -Wextra -Werror  server.c ft_printf/libftprintf.a -o $(NAME) 

clean : 

fclean : clean
	rm server
	rm client

re : fclean all
