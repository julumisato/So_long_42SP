CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I$(INCL_DIR)
MKDIR	=	mkdir -p
RM		=	rm -f
MLXFLAGS =	-lmlx -Ilmlx -lX11 -lXext
##-I$(MLX_DIR) -L $(MLX_DIR) 
NAME	=	so_long

SRCS	=	so_long.c ft_init_game.c ft_map_init.c ft_hook_utils.c ft_close_game.c\
			ft_map_validation.c
OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR =	objs/
INCL_DIR =	includes/
LIB		=	libft/libft.a
# MLX		=	$(MLX_DIR)libmlx.a
# MLX_DIR	=	minilibx/
MAP		=	maps/test.ber

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)
	@echo "\n\n     **** So_long compiling done ****\n\n"

$(OBJ_DIR)%.o: %.c $(LIB)
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@rmdir $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: $(NAME)
	@./$(NAME) $(MAP)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP)

.PHONY: all clean fclean re run valgrind
