# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 14:54:52 by hannkim           #+#    #+#              #
#    Updated: 2022/06/20 16:32:59 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minishell
CC 				= cc
ifdef DEBUG
	CFLAGS		= -g
	#CFLAGS		= -g3 -fsanitize=address
else
	CFLAGS 		= -Wall -Wextra -Werror
endif
AR				= ar rcs
RM				= rm -f

HEADERS 		= ./include/
SRCS_DIR		= ./src/

LIBFT_DIR 		= libft/
LIBFT_FLAGS		= -L ./$(LIBFT_DIR) -lft

# hannakim
LIB_DIR			= /opt/homebrew/Cellar/readline/8.1.2/lib
LIB_HEADER		= /opt/homebrew/Cellar/readline/8.1.2/include

# nayeon
# LIB_DIR="/usr/local/opt/readline/lib"
# LIB_HEADER="/usr/local/opt/readline/include"

LIB_FLAGS		= -lreadline -L $(LIB_DIR) -I $(LIB_HEADER)

SRC_PARSER_DIR	= parser/
SRC_PARSER		= lexical_analyzer.c syntax_analyzer.c token.c \
					syntax_pipe_line.c syntax_command.c syntax_redirects.c \
					syntax_simple_command.c syntax_io_redirect.c

SRC_UTILS_DIR	= utils/
SRC_UTILS		= ft_isspace.c free.c

SRC_BUILTIN_DIR	= builtin/
SRC_BUILTIN		= ft_echo.c ft_cd.c ft_pwd.c ft_export.c ft_unset.c \
							ft_env.c ft_exit.c
SRC_ERROR_DIR	= error/
SRC_ERROR		= throw_error.c

SRC_ENV_DIR	= env/
SRC_ENV		= env_list.c env_utils.c

SRC_FORK_DIR	= fork/
SRC_FORK		= processor.c

SRC				= main.c \
					$(addprefix $(SRC_PARSER_DIR), $(SRC_PARSER)) \
					$(addprefix $(SRC_BUILTIN_DIR), $(SRC_BUILTIN)) \
					$(addprefix $(SRC_ERROR_DIR), $(SRC_ERROR)) \
					$(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS)) \
					$(addprefix $(SRC_ENV_DIR), $(SRC_ENV)) \

SRCS			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS 			= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I$(HEADERS) -o $@ -c $?

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
