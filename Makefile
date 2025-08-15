NAME		=	cub3D

SOURCES		=	main.c error.c map_parsing.c free.c exit.c utils.c hooks.c initialisation.c mini_map.c render.c \
				temp.c window.c movement.c minimap_vector.c dda.c
GNL_SOURCES		=	get_next_line.c get_next_line_utils.c

SRC_DIR		=	sources
OBJ_DIR		=	objects
GNL_DIR		=	get_next_line
HEADERS		=	includes

SRC			=	$(addprefix $(SRC_DIR)/, $(SOURCES))
GNL_SRC		=	$(addprefix $(GNL_DIR)/, $(GNL_SOURCES))
OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(GNL_SRC:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)

ARGS		?=
CC			=	cc
CFLAGS		=	-Werror -Wall -Wextra -I$(HEADERS) -I$(LIBFT) -I$(MINILIB) -I$(GNL_DIR)
MINI_FLAGS	=	-L$(MINILIB) -lmlx -lXext -lX11 -lbsd

# ANSI color codes
BLACK	=	\033[38;2;0;0;0m
RED		=	\033[38;2;255;0;0m
GREEN	=	\033[38;2;0;128;0m
YELLOW	=	\033[38;2;255;255;0m
BLUE	=	\033[38;2;0;0;255m
LIME	=	\033[38;2;0;255;0m
RESET	=	\033[0m # No Color

# compile source files into object files in a directory
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# compile get_next_line files into object files
$(OBJ_DIR)/%.o:$(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# LIBft library
LIBFT		=	./libft
LIBFT_LIB	=	$(LIBFT)/libft.a

# minilibs library
MINILIB		=	./minilibx/minilibx-linux
MINI_LIB	=	$(MINILIB)/libmlx.a

# instructions to make NAME
$(NAME): $(OBJ) $(LIBFT_LIB) $(MINI_LIB)
	@$(CC) $(OBJ) $(LIBFT_LIB) $(MINI_LIB) $(MINI_FLAGS) -lm -o $(NAME)
	@echo "$(LIME)==========================\nSUCCESS : Program compiled\n==========================\n$(RESET)"

# instructions to compile libft
$(LIBFT_LIB):
	@make -C $(LIBFT)
	@echo "$(BLUE)libft: libft.a created$(RESET)"

# build ML42 Library
$(MINI_LIB):
	@make -C $(MINILIB)
	@echo "$(BLUE)minilibx: libmlx.a created$(RESET)"

PHONY: all clean fclean re val run

all: $(LIBFT_LIB) $(MINI_LIB) $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) clean
	@make -C $(MINILIB) clean
	@echo "$(RED)/!\ Objects files removed /!\ $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(MINILIB) clean
	@echo "$(RED)/!\ Executable removed /!\ $(RESET)"

re: fclean all

val: $(NAME)
	@if [ -z "$(ARGS)" ]; then \
		valgrind --suppressions=x11.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes ./$(NAME) maps/map1.cub; \
	else \
		valgrind --suppressions=x11.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes ./$(NAME) $(ARGS); \
	fi

run: $(NAME)
	./$(NAME) maps/map1.cub