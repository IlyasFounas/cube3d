# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME              := cube3d

SRC_DIR           := srcs
DIR_BONUS         := bonus
OBJ_DIR           := objs
INC_DIR           := includes
GNL_DIR           := gnl

LIBFT_DIR         := libft
MLX_DIR           := mlx

LIBFT             := $(LIBFT_DIR)/libft.a
MLX               := $(MLX_DIR)/libmlx.a

CC                := cc
CFLAGS            := -Wall -Wextra -Werror -g3 -std=gnu11 -I$(INC_DIR) -Ilibft -Imlx -I$(GNL_DIR)
SYS_LIBS          := -lm -lXext -lX11 -lz

# **************************************************************************** #
#                                  SOURCES                                     #
# **************************************************************************** #

SRC_COMMON := \
	$(SRC_DIR)/main.c \
	\
	$(SRC_DIR)/graphic_rendering/draw_fps.c \
	$(SRC_DIR)/graphic_rendering/draw_minimap.c \
	$(SRC_DIR)/graphic_rendering/free_rendering.c \
	$(SRC_DIR)/graphic_rendering/graphic_rendering.c \
	$(SRC_DIR)/graphic_rendering/texture_rendering.c \
	\
	$(SRC_DIR)/parsing/color.c \
	$(SRC_DIR)/parsing/color_utils.c \
	$(SRC_DIR)/parsing/hard_coded_parsing.c \
	$(SRC_DIR)/parsing/map.c \
	$(SRC_DIR)/parsing/map_utils.c \
	$(SRC_DIR)/parsing/map_valid.c \
	$(SRC_DIR)/parsing/parse.c \
	$(SRC_DIR)/parsing/parsing_utils.c \
	$(SRC_DIR)/parsing/str_utils.c \
	$(SRC_DIR)/parsing/texture.c \
	$(SRC_DIR)/parsing/texture_utils.c \
	$(SRC_DIR)/parsing/utils.c \
	$(SRC_DIR)/parsing/errors.c \
	\
	$(SRC_DIR)/raycasting/raycasting.c \
	$(SRC_DIR)/raycasting/solving_linear_equa.c \
	$(SRC_DIR)/raycasting/solving_linear_utils.c \
	\
	$(SRC_DIR)/window_handeling/movements_handeling.c \
	$(SRC_DIR)/window_handeling/movements_handeling_utils.c \
	$(SRC_DIR)/window_handeling/window_handeling.c

SRC_BONUS := \
	$(DIR_BONUS)/main_bonus.c \
	$(DIR_BONUS)/raycasting_bonus.c \
	$(DIR_BONUS)/window_handeling_bonus.c

ifeq ($(USE_BONUS),1)
SRC := $(filter-out $(SRC_DIR)/main.c, $(SRC_COMMON)) $(SRC_BONUS)
else
SRC := $(SRC_COMMON)
endif

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

.PHONY: all bonus clean fclean re force

all: $(NAME)

bonus: fclean
	@$(MAKE) USE_BONUS=1 all --no-print-directory

force:

$(LIBFT): force
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX): force
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(SYS_LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory || true
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory || true

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory || true

re: fclean all
