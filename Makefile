CC				=	gcc
'CFLAGS			=	-Wextra -Werror -Wall

NAME 			=	fdf

SRC_DIR			=	src
OBJ_DIR			=	obj

SRC = $(shell find $(SRC_DIR) -type f -name "*.c" | cut -b 5-)
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

LIBFT			=	libft.a
DIR_LIBFT		=	libft

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

all: $(OBJ_DIR) 
	$(MAKE) -C $(DIR_LIBFT)
	$(MAKE) -j $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L./$(DIR_LIBFT) -lft -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
