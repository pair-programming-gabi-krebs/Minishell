NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3

LIB_FLAG = -lreadline

CC = gcc

SRC_PATH = ./prompt/

SRC_FILES = main.c \
			ft_init.c \
			prompt.c \
			print_dir.c \
			history.c

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

OBJ_PATH = ./objs/

SRC_OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n █

all: $(NAME)

$(NAME): $(OBJ_PATH) $(SRC_OBJ)
	@echo " 100% complete"
	@echo -n "libft     : "
	@$(MAKE) --no-print-directory -C ./libft
	@$(CC) $(CFLAGS) $(SRC_OBJ) $(LIB_FLAG) ./libft/libft.a -o $(NAME)

$(OBJ_PATH):
	@echo -n "minishell : "
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