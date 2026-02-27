
MAKEFLAGS += --no-print-directory

NAME = libft.a

SRC_DIR = src
INC_DIR = include
OBJ_DIR = objects

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I$(INC_DIR)
AR      = ar
ARFLAGS = rcs

HEADERS = $(wildcard $(INC_DIR)/*.h)

SRCS = \
	$(SRC_DIR)/ft_atoi.c \
	$(SRC_DIR)/ft_bzero.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_isalnum.c \
	$(SRC_DIR)/ft_isalpha.c \
	$(SRC_DIR)/ft_isascii.c \
	$(SRC_DIR)/ft_isdigit.c \
	$(SRC_DIR)/ft_isprint.c \
	$(SRC_DIR)/ft_itoa.c \
	$(SRC_DIR)/ft_memchr.c \
	$(SRC_DIR)/ft_memcmp.c \
	$(SRC_DIR)/ft_memcpy.c \
	$(SRC_DIR)/ft_memmove.c \
	$(SRC_DIR)/ft_memset.c \
	$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c \
	$(SRC_DIR)/ft_putnbr_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_striteri.c \
	$(SRC_DIR)/ft_strjoin.c \
	$(SRC_DIR)/ft_strlcat.c \
	$(SRC_DIR)/ft_strlcpy.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_strmapi.c \
	$(SRC_DIR)/ft_strncmp.c \
	$(SRC_DIR)/ft_strnstr.c \
	$(SRC_DIR)/ft_strrchr.c \
	$(SRC_DIR)/ft_strtrim.c \
	$(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_tolower.c \
	$(SRC_DIR)/ft_toupper.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
