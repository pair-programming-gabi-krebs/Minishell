NAME = minishell

FLAGS = -Wall -Wextra -Werror -g3

CC = gcc

SRC_PATH = ./prompt/
SRC_FILES = main.c

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

OBJ_PATH = ./objs/
SRC_OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo -n █

all: $(NAME)

$(NAME): $(OBJ_PATH) $(SRC_OBJ)
	@echo " 100% complete"
	@echo -n "libft     : "
	@$(MAKE) --no-print-directory -C ./libft
	@$(CC) $(FLAGS) $(SRC_OBJ) ./libft/libft.a -o $(NAME)

$(OBJ_PATH):
	@echo -n "push_swap : "
	@mkdir -p objs
	@echo -n █

clean:
	@echo -n "clean     : "
	@$(MAKE) --no-print-directory -C ./libft clean
	@rm -f $(SRC_OBJ)
	@echo -n █
	@echo " 100% complete"

fclean: clean
	@echo -n "fclean    : "
	@$(MAKE) --no-print-directory -C ./libft fclean
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME)
	@echo -n █
	@echo " 100% complete"

re: fclean all