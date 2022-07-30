NAME = minishell

SRC = minishell.c ./42-Libft/*.c

$(DIR_OBJS) = $(SRC:.c=.o)

$(NAME) : $(DIR_OBJS)
	gcc $(SRC) -l readline -o $(NAME)

re : fclean all

clean :
	rm -rf  *.o $(NAME)

fclean : clean

norm :
	norminette