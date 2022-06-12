# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 14:54:52 by hannkim           #+#    #+#              #
#    Updated: 2022/06/20 15:22:36 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minishell
CC 				= cc
ifdef DEBUG
	CFLAGS		= -g3 -fsanitize=address
else
	CFLAGS 		= -Wall -Wextra -Werror
endif
AR				= ar rcs
RM				= rm -f

HEADERS 		= ./include/
SRCS_DIR		= ./src/

LIBFT_DIR 		= ./libft/
LIBFT_FLAGS		= -L ./$(LIBFT_DIR) -lft

# hannakim
LIB_DIR			= /opt/homebrew/Cellar/readline/8.1.2/lib
LIB_HEADER		= /opt/homebrew/Cellar/readline/8.1.2/include

# nayeon
# LIB_DIR="/usr/local/opt/readline/lib"
# LIB_HEADER="/usr/local/opt/readline/include"

LIB_FLAGS		= -lreadline -L $(LIB_DIR) -I $(LIB_HEADER)

PARSER_DIR_SRC	= parser/
PARSER_SRC		= lexer.c parser.c

UTILS_DIR_SRC	= utils/
UTILS_SRC		= ft_isspace.c

SRC				= main.c \
				$(addprefix $(UTILS_DIR_SRC), $(UTILS_SRC)) \
				$(addprefix $(PARSER_DIR_SRC), $(PARSER_SRC))
SRCS			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS 			= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIB_FLAGS) $(LIBFT_FLAGS) -I $(HEADERS) -o $(NAME) $(OBJS)

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) a.out a.out.dSYM

.PHONY	: fclean
fclean	: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) a.out a.out.dSYM

.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all

.PHONY	: debug
debug	:
	make DEBUG=1 all
