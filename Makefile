# Makefile pour cube3d
NAME        := cube3d

SRC_DIR     := srcs
INC_DIR     := includes
OBJ_DIR     := objs

# découverte automatique des sources
SRC         := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ         := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g3 -std=gnu11 -I$(INC_DIR) -Ilibft -Imlx

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

MLX_DIR     := mlx
MLX         := $(MLX_DIR)/libmlx.a

# libs système (Linux). Ajuste si tu es sur macOS.
SYS_LIBS    := -lm -lXext -lX11 -lz

.PHONY: all clean fclean re force

all: $(NAME)

# ---------- force : permet d'invoquer systématiquement make -C sur les libs
# (utile si tu veux t'assurer que les Makefiles internes sont lancés)
force:

# Construire les libs via leur Makefile
$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): force
	$(MAKE) -C $(MLX_DIR)

# Link final : on link directement les archives construites
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(SYS_LIBS) -o $(NAME)

# compilation .c -> .o (crée l'arbo obj si besoin)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# nettoyage
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean || true
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all
