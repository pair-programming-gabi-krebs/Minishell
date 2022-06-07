NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3

LIB_FLAG = -lreadline

CC = gcc

VPATH = prompt lexer parser utils builtins pipeline


FILES = main.c \
		ft_free.c \
		ft_init.c \
		ft_exit.c \
		ft_reset.c \
		prompt.c \
		print_dir.c \
		history.c \
		lexer.c \
		tokenizer.c \
		special_case.c \
		signal.c \
		pre_token.c \
		check_special_tokens.c \
		valid_input.c \
		pre_token_utils.c \
		cd.c \
		env.c \
		unset.c \
		export.c \
		copy_envp.c \
		pwd.c \
		echo.c \
		remove_quotes.c \
		pipeline.c \
		pipex.c \
		command_finder.c \
		parse_env.c \
		dup42.c \
		is_builtin.c \
		exec_builtin.c \
		build_cmd_table.c \
		exec_commands.c \
		resolve_dups_outfile.c \
		resolve_dups_infile.c \
		format_table.c \
		create_process_and_exec_cmd.c \
		end_pipeline.c \
		reset_cmd_table.c \
		copy_mtx.c \
		handle_redirects.c \
		check_for_redirects.c \
		get_last_redirect_position.c \
		get_redirect_name.c \
		remove_redirect_from_end_of_str.c \
		remove_redirect_from_start_of_str.c \
		pre_tokenization.c \
		line_formater.c \
		strjoin_quotes.c \
		strjoin_add_space.c \
		check_expand_var.c



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

valgrind: re
	clear
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell