CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I$(INCL_DIR)
MKDIR	=	mkdir -p
RM		=	rm -f
MLXFLAGS =	-lmlx -lX11 -lXext

NAME	=	so_long

SRCS	=	so_long.c
OBJS	=	$(SRCS:.c=.o)
INCL_DIR =	includes/
LIB		=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)

$(OBJS): $(SRCS) $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

run: $(NAME)
	./$(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(NAME) $(MAP)

.PHONY: all clean fclean re run valgrind