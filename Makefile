CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = SRC/main.c SRC/pipex.c SRC/parsing.c SRC/struct_list.c SRC/utile.c
SRC_BONUS = SRC_BONUS/main_bonus.c SRC_BONUS/pipex_bonus.c SRC_BONUS/parsing_bonus.c SRC_BONUS/struct_list_bonus.c SRC_BONUS/utile_bonus.c SRC_BONUS/here_doc_bonus.c
NAME = pipex

all: $(NAME)

$(NAME) : $(SRC)
	@echo "\033[33m----Compiling lib----"
	@make -C ./Includes/libft
	
	@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
	$(CC) $(CFLAGS) $^ -L./Includes/libft -lft -o $(NAME)

clean : 
	@make clean -C ./Includes/libft
	rm -f $(NAME)

fclean : clean
	@make fclean -C ./Includes/libft
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re : fclean all

bonus : $(SRC_BONUS)
	@echo "\033[33m----Compiling lib----"
	@make -C ./Includes/libft
	
	@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
	$(CC) $(CFLAGS) $^ -L./Includes/libft -lft -o $(NAME)

.PHONY : all clean fclean re bonus
