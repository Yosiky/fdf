CC				=	gcc
CFLAGS			=	-Wextra -Werror -Wall

NAME 			=	fdf

SRC_DIR			=	src
OBJ_DIR			=	obj

SRC = $(shell find $(SRC_DIR) -type f -name "*.c" | cut -b 5-)
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(OBJ_DIR)
	$(MAKE) -j $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
