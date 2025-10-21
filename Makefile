NAME        := cube3d

SRC_DIR     := srcs
INC_DIR     := includes
OBJ_DIR     := objs
GNL_DIR     := gnl

SRC         := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

GNL_SRC     := $(shell find $(GNL_DIR) -type f -name "*.c")
GNL_OBJ     := $(patsubst $(GNL_DIR)/%.c,$(OBJ_DIR)/gnl/%.o,$(GNL_SRC))

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g3 -std=gnu11 -I$(INC_DIR) -Ilibft -Imlx -I$(GNL_DIR)

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

MLX_DIR     := mlx
MLX         := $(MLX_DIR)/libmlx.a

SYS_LIBS    := -lm -lXext -lX11 -lz

.PHONY: all clean fclean re force

all: $(NAME)

force:

$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): force
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT) $(MLX) $(SYS_LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/gnl/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean || true
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all