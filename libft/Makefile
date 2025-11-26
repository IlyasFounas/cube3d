# NAME		= libft.a

# SRC			=	ft_atoi.c\
# 				ft_atoi_error.c\
# 				ft_bzero.c\
# 				ft_isalpha.c\
# 				ft_isascii.c\
# 				ft_isdigit.c\
# 				ft_isprint.c\
# 				ft_memcpy.c\
# 				ft_memset.c\
# 				ft_memmove.c\
# 				ft_strchr.c\
# 				ft_strlcpy.c\
# 				ft_strlen.c\
# 				ft_strncmp.c\
# 				ft_strrchr.c\
# 				ft_tolower.c\
# 				ft_toupper.c\
# 				ft_isalnum.c\
# 				ft_strlcat.c\
# 				ft_memchr.c\
# 				ft_memcmp.c\
# 				ft_strnstr.c\
# 				ft_calloc.c\
# 				ft_strdup.c\
# 				ft_substr.c\
# 				ft_strjoin_sh.c\
# 				ft_strjoin.c\
# 				ft_split_sh.c\
# 				ft_split.c\
# 				ft_itoa.c\
# 				ft_strtrim.c\
# 				ft_strmapi.c\
# 				ft_striteri.c\
# 				ft_putchar_fd.c\
# 				ft_putstr_fd.c\
# 				ft_putendl_fd.c\
# 				ft_putnbr_fd.c\
# 				get_next_line.c

# SRC_BONUS	=	ft_lstnew.c\
# 				ft_lstadd_front.c\
# 				ft_lstsize.c\
# 				ft_lstlast.c\
# 				ft_lstadd_back.c\
# 				ft_lstdelone.c\
# 				ft_lstclear.c\
# 				ft_lstiter.c\
# 				ft_lstmap.c

# OBJ_DIR 		= objs
# OBJ				= $(SRC:.c=.o)
# OBJ_BONUS		= $(OBJ) $(SRC_BONUS:.c=.o)
# CFLAGS			= -Wall -Wextra -Werror -g3 
# CC				= cc

# $(NAME): $(OBJ) libft.h Makefile
# 	ar rcs $(NAME) $(OBJ)

# $(OBJ_DIR)/%.o: %.c libft.h | $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR) && echo "Création du répertoire objs/"

# clean:
# 	rm -f $(OBJ) $(OBJ_BONUS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# all: $(NAME)

# bonus: $(OBJ_BONUS)
# 	@$(MAKE) --no-print-directory OBJ="$(OBJ_BONUS)"

# .PHONY: all bonus clean fclean re

NAME        = libft.a

SRC         = ft_atoi.c \
			  ft_atoi_error.c \
			  ft_bzero.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_memcpy.c \
			  ft_memset.c \
			  ft_memmove.c \
			  ft_strchr.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strncmp.c \
			  ft_strrchr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_isalnum.c \
			  ft_strlcat.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strnstr.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin_sh.c \
			  ft_strjoin.c \
			  ft_split_sh.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strtrim.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  get_next_line.c

SRC_BONUS   = ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

OBJ_DIR     = objs
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS   = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

$(OBJ_DIR)/%.o: %.c libft.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
