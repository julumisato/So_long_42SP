CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I$(INCL_DIR)
MKDIR	=	mkdir -p
RM		=	rm -f
MLXFLAGS =	-lmlx -Ilmlx -lX11 -lXext
##-I$(MLX_DIR) -L $(MLX_DIR) 
NAME	=	so_long

SRCS	=	so_long.c ft_init_game.c ft_map_init.c ft_hook_utils.c ft_close_game.c\
			ft_map_validation.c ft_move_utils.c ft_path_check.c
OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR =	objs/
INCL_DIR =	includes/
LIB		=	libft/libft.a
LIB_DIR	=	libft/
# MLX		=	$(MLX_DIR)libmlx.a
# MLX_DIR	=	minilibx/
MAP		=	maps/map2.ber

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)
	@echo "\n\n     **** So_long compiling done ****\n\n"

$(OBJ_DIR)%.o: %.c $(LIB)
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make -C $(LIB_DIR)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIB_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all

run: $(NAME)
	@./$(NAME) $(MAP)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP)

.PHONY: all clean fclean re run valgrind
