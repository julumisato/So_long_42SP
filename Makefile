# Compilation & Shell Commands
CC =		cc
CFLAGS = 	-Wall -Wextra -Werror -I $(HDR_PATH)
MKDIR =		mkdir -p
RM =		rm -f

# Paths
HDR_PATH =	./includes/
SRC_PATH =	./srcs/
LIB_PATH =	./libs/
OBJ_PATH =	./objs/
BIN_PATH =	./bin/

# Files
NAME =		$(BIN_PATH)so_long
SRC_FILES =	so_long.c
SRCS =		$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ_FILES =	$(patsubst %.c, %.o, $(SRC_FILES))
OBJS =		$(addprefix $(OBJ_PATH), $(OBJ_FILES))
LIB =		$(LIB_PATH)libft.a
MAP =		./maps/map.ber

# TARGETS
all: $(BIN_PATH) $(NAME)

$(BIN_PATH):
	@$(MKDIR) $(BIN_PATH)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lmlx -lXext -lX11 $(LIB)

$(LIB):
	@make -C $(LIB_PATH)

$(OBJS): $(SRCS)
	@$(MKDIR) $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I $(HDR_PATH) -c $< -o $@

run: $(NAME)
	@$(NAME) $(MAP)

clean:
	@$(RM) $(OBJS)
	@make fclean -C $(LIB_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(NAME) $(MAP)

.PHONY: all clean fclean re run
