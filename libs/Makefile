# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 21:19:04 by jusato            #+#    #+#              #
#    Updated: 2022/05/11 19:22:51 by jusato           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c

BONUS_OBJ	= $(BONUS:.c=.o)

CC			= cc
FLAGS		= -Wall -Wextra -Werror
AR			= ar -rcs
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
		$(CC) $(FLAGS) -c $(SRCS) -I .

clean:
		$(RM) $(OBJS) $(BONUS_OBJ)

fclean: clean
		$(RM) $(NAME)

re : fclean all

bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $?

$(BONUS_OBJ): $(BONUS)
	$(CC) $(FLAGS) -c $(BONUS) -I .
	

.PHONY: all clean fclean re
