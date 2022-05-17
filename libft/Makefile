# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 15:27:40 by lkrebs-l          #+#    #+#              #
#    Updated: 2022/05/10 22:01:03 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
					ft_lstlast.c ft_lstdelone.c ft_lstclear.c strichar.c ft_mtxlen.c \
					ft_count_char.c gnl.c

NAME = libft.a

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

CFLAGS = -g3 -Wextra -Werror -Wall

CC = gcc

RM = rm -rf

OBJ_DIR = ./objs/

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n █

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo -n █
	@echo " 100% complete"

$(OBJ_DIR):
	@mkdir -p objs
	@echo -n █

clean:
	@$(RM) $(OBJ)
	@echo -n █

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR)
	@echo -n █

re: fclean $(NAME)

.PHONY: all clean fclean re
