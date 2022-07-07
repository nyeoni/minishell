# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 22:59:15 by nkim              #+#    #+#              #
#    Updated: 2022/07/07 16:39:41 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
HEADERS	= -I.

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar
AFLAGS	= rcs
SRC	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
		ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_realloc.c ft_ptrrealloc.c\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c
OBJ	=	$(SRC:.c=.o)

all : $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@$(AR) $(AFLAGS) $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $?

.PHONY : all clean fclean re