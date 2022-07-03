# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 14:54:52 by hannkim           #+#    #+#              #
#    Updated: 2022/07/03 16:41:09 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minishell
CC 				= cc

ifdef DEBUG
	CFLAGS		= -g3 -fsanitize=address
else ifdef LEAKS
	CFLAGS		= -g
else
	CFLAGS 		= -Wall -Wextra -Werror
endif

GITUSER := $(USER)
ifeq ($(GITUSER), chloek)
	LDFLAGS		= -L/usr/local/opt/readline/lib
	CPPFLAGS	= -I/usr/local/opt/readline/include
else ifeq ($(GITUSER), hannkim)
	LDFLAGS		= -L/opt/homebrew/Cellar/readline/8.1.2/lib
	CPPFLAGS	= -I/opt/homebrew/Cellar/readline/8.1.2/include
else
	LDFLAGS		:= $(LDFLAGS)
	CPPFLAGS	:= $(CPPFLAGS)
endif

AR				= ar rcs
RM				= rm -f

HEADERS 		= ./include/
SRCS_DIR		= ./src/

LIBFT_DIR 		= libft/
LIBFT_FLAGS		= -L ./$(LIBFT_DIR) -lft

LIB_FLAGS		= -lreadline $(LDFLAGS) $(CPPFLAGS)

SRC_PARSER_DIR	= parser/
SRC_PARSER		= lexical_analyzer.c syntax_analyzer.c token.c \
					syntax_pipe_line.c syntax_command.c syntax_redirects.c \
					syntax_simple_command.c syntax_io_redirect.c syntax_word.c \
					syntax_heredoc_word.c get_combined_word.c \
					free_ast.c free_simple_command.c free_io_redirect.c

SRC_BUILTIN_DIR	= builtin/
SRC_BUILTIN		= ft_echo.c ft_cd.c ft_pwd.c ft_export.c ft_unset.c \
							ft_env.c ft_exit.c is_builtin.c check_option.c
SRC_ERROR_DIR	= error/
SRC_ERROR		= throw_error.c throw_error_env.c throw_error_exit.c \
					throw_error_usage.c throw_error_syntax.c

SRC_ENV_DIR		= env/
SRC_ENV			= get_env.c valid_env_name.c get_env_name.c \
					get_env_value.c add_env.c remove_env.c free_env.c

SRC_SUBSHELL_DIR= subshell/
SRC_SUBSHELL	= wait_subshell.c create_subshell.c

SRC_REDIRECT_DIR= redirect/
SRC_REDIRECT	= redirect_in_file.c redirect_out_file.c redirect_append_file.c \
					redirect_heredoc.c backup_std_fd.c reset_std_fd.c redirect_out_trash.c

SRC_MANAGER_DIR	= manager/
SRC_MANAGER		=

SRC_TEST_DIR	= __test__/
SRC_TEST		= test_token.c test_ast.c test_builtin.c test_general.c

SRC_EXEC_DIR	= exec/
SRC_EXEC		= exec_command_line.c \
					exec_heredoc.c exec_general.c exec_builtin.c \
					exec_subshell.c exec_single_command.c \
					exec_simple_command.c exec_io_redirect.c

SRC_SIGNAL_DIR	= signal/
SRC_SIGNAL		= init_signal.c change_signal.c heredoc_signal.c multishell_signal.c

SRC_UTILS_DIR	= utils/
SRC_UTILS		= bs_isspace.c bs_exit_eof.c bs_strcmp.c bs_calloc.c bs_find_path.c

SRC				= main.c \
					$(addprefix $(SRC_PARSER_DIR), $(SRC_PARSER)) \
					$(addprefix $(SRC_BUILTIN_DIR), $(SRC_BUILTIN)) \
					$(addprefix $(SRC_REDIRECT_DIR), $(SRC_REDIRECT)) \
					$(addprefix $(SRC_SUBSHELL_DIR), $(SRC_SUBSHELL)) \
					$(addprefix $(SRC_ERROR_DIR), $(SRC_ERROR)) \
					$(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS)) \
					$(addprefix $(SRC_ENV_DIR), $(SRC_ENV)) \
					$(addprefix $(SRC_TEST_DIR), $(SRC_TEST)) \
					$(addprefix $(SRC_EXEC_DIR), $(SRC_EXEC)) \
					$(addprefix $(SRC_SIGNAL_DIR), $(SRC_SIGNAL))

SRCS			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS 			= $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -I $(HEADERS) $(CPPFLAGS) -o $@ -c $?
	@echo $(CUT)$(BOLD)$(MINT) Compiling with $(CFLAGS)...$(RESET)
	@echo $(CUT)$(MAUVE) [$(notdir $^)] to [$(notdir $@)] $(RESET)
	@printf $(UP)$(UP)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LIB_FLAGS) $(LIBFT_FLAGS) -o $(NAME) $(OBJS)
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨BLACKHOLE-SHELL✨ $(GREEN)is ready 🎉 $(RESET)

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) a.out a.out.dSYM
	@echo $(BOLD)$(MAUVE) 🗒 object files $(PINK)have been cleaned....🗑️$(RESET)


.PHONY	: fclean
fclean	: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) a.out a.out.dSYM
	@echo $(BOLD)$(L_PURPLE) ✨BLACKHOLE-SHELL✨ $(PINK)has been cleaned....🗑️$(RESET)


.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all

.PHONY	: debug
debug	:
	@make DEBUG=1 all

.PHONY	: leaks
leaks	:
	@make LEAKS=1 all

######################### Color #########################
GREEN="\033[32m"
MINT="\033[38;5;51m"
L_PURPLE="\033[38;5;55m"
MAUVE="\033[38;5;147m"
PINK="\033[38;5;175m"
RESET="\033[0m"
BOLD="\033[1m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"