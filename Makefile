CC				=	gcc
CFLAGS			=	-Wextra -Werror -Wall

NAME 			=	fdf

SRC_DIR			=	src
OBJ_DIR			=	obj

SRC				=	$(shell find $(SRC_DIR) -type f -name "*.c" | cut -b 5-)
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
HEADER			=	src/event.h		\
					src/fdf.h


LIBFT			=	libft.a
DIR_LIBFT		=	libft

DIR_MLX			=	minilibx

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(OBJ_DIR) 
	$(MAKE) -C $(DIR_MLX)
	$(MAKE) -C $(DIR_LIBFT)
	$(MAKE) -j $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) libft/libft.a minilibx/libmlx.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

re: fclean all
