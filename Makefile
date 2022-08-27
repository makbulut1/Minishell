NAME = minishell

SRC = $(wildcard *.c)

DIR_OBJS = $(SRC:%.c=./obj/%.o)

all : $(NAME)

$(NAME) : $(DIR_OBJS)
	@make -C 42-Libft
	@gcc $(SRC) -l readline -o $(NAME) 42-Libft/libft.a

obj/%.o : ./%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) -c $< -o $@

re : fclean all

clean :
	@make clean -C 42-Libft
	@rm -rf  obj *.o

fclean :
	@make fclean -C 42-Libft
	@rm -rf  obj *.o $(NAME)
norm :
	norminette