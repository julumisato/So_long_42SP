# Paths
HDR_PATH =	./includes/
SRC_PATH =	./srcs/
LIB_PATH =	./libs/
OBJ_PATH =	./objs/
BIN_PATH =	./bin/

# Compilation
CC =		gcc
CFLAGS = 	-Wall -Wextra -Werror -I $(HDR_PATH)

# Other commands
MKDIR =		mkdir -p
RM =		rm -f

# Files
NAME =		$(BIN_PATH)so_long
SRC_FILES =	so_long.c
SRCS =	$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ_FILES =	$(patsubst %.c, %.o, $(SRC_FILES))
OBJS =	$(addprefix $(OBJ_PATH), $(OBJ_FILES))
LIB =		$(LIB_PATH)libft.a

# TARGETS

all: $(BIN_PATH) $(NAME)

$(BIN_PATH):
	@$(MKDIR) $(BIN_PATH)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lmlx -lXext -lX11 -L $(LIB_PATH) -lft

$(LIB):
	make --no-print-directory -C $(LIB_PATH)

$(OBJS): $(SRCS)
	@$(MKDIR) $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	$(NAME)

# Clean
clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIB_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
