NAME		=	cub3D

GRAPHICAL_SOURCES	=	dda.c error.c exit.c free.c hooks.c initialisation.c main.c mini_map.c \
					minimap_vector.c movement.c open_textures.c render.c render_utils.c \
					render_walls.c utils.c window.c

PARSING_SOURCES		=	arg_validator.c atributes_validator.c error_handling.c init_atributes.c \
					instantiate_data.c map_validator.c parse_data.c utils.c main_parsing.c \
					init_map.c

GNL_SOURCES		=	get_next_line.c get_next_line_utils.c

SRC_DIR		=	sources
GRAPHICAL_DIR	=	$(SRC_DIR)/graphical
PARSING_DIR	=	$(SRC_DIR)/parsing
OBJ_DIR		=	objects
GNL_DIR		=	get_next_line
HEADERS		=	includes

GRAPHICAL_SRC	=	$(addprefix $(GRAPHICAL_DIR)/, $(GRAPHICAL_SOURCES))
PARSING_SRC	=	$(addprefix $(PARSING_DIR)/, $(PARSING_SOURCES))
GNL_SRC		=	$(addprefix $(GNL_DIR)/, $(GNL_SOURCES))

OBJ			=	$(GRAPHICAL_SRC:$(GRAPHICAL_DIR)/%.c=$(OBJ_DIR)/graphical/%.o) \
				$(PARSING_SRC:$(PARSING_DIR)/%.c=$(OBJ_DIR)/parsing/%.o) \
				$(GNL_SRC:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)

# LIBft library
LIBFT		=	./libft
LIBFT_LIB	=	$(LIBFT)/libft.a

# minilibs library
MINILIB		=	./minilibx/minilibx-linux
MINI_LIB	=	$(MINILIB)/libmlx.a

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

#compile graphical source files into object files
$(OBJ_DIR)/graphical/%.o:$(GRAPHICAL_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# compile parsing source files into object files
$(OBJ_DIR)/parsing/%.o:$(PARSING_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# compile get_next_line files into object files
$(OBJ_DIR)/%.o:$(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# instructions to make NAME
$(NAME): $(OBJ) $(LIBFT_LIB) $(MINI_LIB)
	@$(CC) $(OBJ) -L$(LIBFT) -lft $(MINI_LIB) $(MINI_FLAGS) -lm -o $(NAME)
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
