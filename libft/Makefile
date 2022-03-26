# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 15:27:40 by lkrebs-l          #+#    #+#              #
#    Updated: 2022/03/26 19:47:11 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_SOURCE = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c

NAME = libft.a

CFLAGS = -Wextra -Werror -Wall

CC = clang

RM = rm -f

OBJ = $(C_SOURCE:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
			ft_lstlast.c ft_lstdelone.c ft_lstclear.c

VPATH = ./src/

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo -n █

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo -n █
	@echo " 100% complete"

bonus: $(B_OBJ)
	@ar -rc $(NAME) $(B_OBJ)
	@echo -n █

clean:
	@$(RM) $(OBJ)
	@echo -n █

fclean: clean
	@$(RM) $(NAME)
	@echo -n █

re: fclean $(NAME)

.PHONY: all clean fclean re
