# Compilation & Shell Commands
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g -I$(HDR_DIR)
MKDIR =		mkdir -p
RM =		rm -f
MLXFLAGS =	-lmlx -lXext -lX11

# Files
BIN_DIR =	bin/
NAME =		$(BIN_DIR)so_long

SRC_DIR =	srcs/
SRC_FILES =	ft_map_utils.c so_long.c
SRCS =		$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR =	objs/
OBJS =		$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

LIB_DIR =	libft/
LIB =		$(LIB_DIR)libft.a

HDR_DIR =	includes/

MAP =		./maps/map.ber

# TARGETS
all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
	@$(MKDIR) $(BIN_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(MLXFLAGS) -o $@ -L $(LIB_DIR) -lft
	@echo "\n\n       *** So_long compiling done ****        \n\n"

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIB)
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	@$(NAME) $(MAP)

clean:
	@$(RM) $(OBJS) $(SOLONG_A)
	@rmdir $(OBJ_DIR)
	@make clean -C $(LIB_DIR)

fclean: clean
	@$(RM) $(NAME)
	@rmdir $(BIN_DIR)
	@make fclean -C $(LIB_DIR)

re: fclean all

valgrind:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(NAME) $(MAP)

runtest: $(NAME)
	@$(NAME) $(MAP)

.PHONY: all clean fclean re run valgrind
