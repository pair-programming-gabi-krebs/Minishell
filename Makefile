NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3

LIB_FLAG = -lreadline

CC = gcc

VPATH = prompt lexer parser

FILES = main.c \
		ft_init.c \
		prompt.c \
		print_dir.c \
		history.c \
		common_case.c \
		handle_redirect.c \
		lexer.c \
		tokenizer.c \
		special_case.c \
		signal.c \
		parser.c

OBJ_PATH = ./objs/

OBJS = $(FILES:%.c=$(OBJ_PATH)%.o)

$(OBJ_PATH)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n █

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@echo " 100% complete"
	@echo -n "libft     : "
	@$(MAKE) --no-print-directory -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAG) ./libft/libft.a -o $(NAME)

$(OBJ_PATH):
	@echo -n "minishell : "
	@mkdir -p objs
	@echo -n █

clean:
	@echo -n "clean     : "
	@$(MAKE) --no-print-directory -C ./libft clean
	@rm -f $(OBJS)
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