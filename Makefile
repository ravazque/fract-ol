
MAKEFLAGS += --no-print-directory

NAME        = fractol

SRC_DIR     = src
INC_DIR     = include

LIBFT_DIR   = src/aux_libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

MLX_DIR     = linux-minilibx
MLX_A       = $(MLX_DIR)/libmlx.a

OBJ_DIR     = objects

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LDFLAGS  = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

HEADERS = $(wildcard $(INC_DIR)/*.h)
LIBFT_HEADERS = $(LIBFT_DIR)/include/libft.h

SRCS = \
	$(SRC_DIR)/fractol.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/math_utils.c \
	$(SRC_DIR)/events.c \
	$(SRC_DIR)/string_utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RESET           = \033[0m
TURQUOISE       = \033[0;36m
LIGHT_TURQUOISE = \033[1;36m
DARK_BLUE       = \033[0;34m
LIGHT_GREEN     = \033[1;32m
LIGHT_RED       = \033[1;91m

all:
	@if $(MAKE) -q $(NAME) 2>/dev/null; then \
		printf "make: Nothing to be done for 'all'.\n"; \
	else \
		msg=""; \
		if [ ! -f "$(MLX_A)" ]; then \
			msg="minilibx"; \
		fi; \
		if [ ! -f "$(LIBFT_A)" ]; then \
			if [ -n "$$msg" ]; then msg="$$msg, "; fi; \
			msg="$${msg}libft"; \
		fi; \
		needs_fractol=0; \
		if [ ! -f "$(NAME)" ]; then \
			needs_fractol=1; \
		elif [ ! -f "$(MLX_A)" ] || [ ! -f "$(LIBFT_A)" ]; then \
			needs_fractol=1; \
		fi; \
		if [ $$needs_fractol -eq 1 ]; then \
			if [ -n "$$msg" ]; then msg="$$msg & "; fi; \
			msg="$${msg}fractol"; \
		fi; \
		if [ -n "$$msg" ]; then \
			printf "$(DARK_BLUE)Compiling $$msg...$(RESET)\n"; \
		fi; \
		$(MAKE) $(NAME); \
	fi

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LDFLAGS) -o $@
	@printf "$(LIGHT_TURQUOISE)fractol ready!$(RESET)\n"

$(MLX_A):
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) $(LIBFT_HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@printf "$(LIGHT_RED)Running an object cleanup...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(TURQUOISE)Cleaning of objects completed!$(RESET)\n"

fclean:
	@printf "$(LIGHT_RED)Running a full cleanup...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(TURQUOISE)Full cleaning finished!$(RESET)\n"

re:
	@$(MAKE) fclean
	@printf "———\n"
	@$(MAKE) -s all

.PHONY: all clean fclean re

# ----------------------------------------------------------------------------------------------------------------

# "make" works based on whether it is compiled or not, but a make clean can sometimes make it seem like
# there is a relink or no recompilation messages appear, such as from libft. This is for aesthetic reasons,
# as it is based on the ".a" files, and it does not affect the compilation, program operation, or relinks.

# If "Makefile.gen" does not exist inside the mlx directory and you try to run "make fclean" (for example,
# immediately after cloning the repository), the makefile will return an error due to the absence of this
# mlx file. This is due to the different systems on which mlx has been used. It is not an error!

# ----------------------------------------------------------------------------------------------------------------
