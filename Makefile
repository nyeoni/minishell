# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 20:36:43 by nkim              #+#    #+#              #
#    Updated: 2022/05/28 21:17:28 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= minishell

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -rf

LIBFT_DIR				= ./libft/
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/

INCS					= -I include

SRC						= main.c
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

SRC_BONUS				= main_bonus.c utils_bonus.c
SRCS_BONUS				= $(addprefix $(SRCS_DIR_BONUS), $(SRC_BONUS))
OBJS_BONUS				= $(SRCS_BONUS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(INCS_DIR_BONUS) -o $@ -c $?

$(NAME) : $(OBJS)
	@echo "\033[33m----Compiling lib----"
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) -I $(INCS_DIR)
	@echo "\n----Pipex Compiled! 😻----"

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS) a.out.dSYM

fclean : clean
	@echo "\n\033[31m----Delete everything 👌!----"
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) a.out.dSYM
	@echo "\n\033[31m----fclean done 👌!----\n"

re : fclean all

bonus : $(OBJS_BONUS)
	@echo "\033[33m----Compiling lib----"
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJS_BONUS) $(LIBFT_FLAGS) -I $(INCS_DIR_BONUS)
	@echo "\n----Pipex bonus Compiled! 😻----"

test :
	make -C $(LIBFT_DIR)
	$(CC) -g -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

leak :
	make -C $(LIBFT_DIR)
	$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

bonus_leak :
	make -C $(LIBFT_DIR)
	$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS_BONUS) $(LIBFT_FLAGS) -I $(INCS_DIR_BONUS)

norm :
	norminette $(SRCS) $(INCS_DIR)

PHONY	: all clean fclean re bonus