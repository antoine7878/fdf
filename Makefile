# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 21:31:05 by ale-tell          #+#    #+#              #
#    Updated: 2024/11/27 11:02:20 by ale-tell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc

CDIR = ./src
CDIR_BONUS = ./src_bonus
HDIR = ./include
ODIR = ./obj
ODIR_BONUS = ./obj_bonus

SRC =	$(CDIR)/fdf.c \
		$(CDIR)/put_utils.c \
		$(CDIR)/put_map.c \
		$(CDIR)/color.c \
		$(CDIR)/map.c \
		$(CDIR)/trigo.c \
		$(CDIR)/count_lines.c \
		$(CDIR)/split_atoi.c \
		$(CDIR)/controls.c \
		$(CDIR)/on_mouse.c \
		$(CDIR)/on_key.c \
		$(CDIR)/transform.c \
		$(CDIR)/map_limits.c

LIBFT = libft/libft.a

### Compile ###
OBJ = $(patsubst $(CDIR)/%.c, $(ODIR)/%.o, $(SRC))
SRC_BONUS = $(patsubst $(CDIR)/%.c, $(CDIR_BONUS)/%.o, $(SRC))
OBJ_BONUS = $(patsubst $(CDIR)/%.c, $(ODIR_BONUS)/%.o, $(SRC))
CFLAGS = -Wall -Wextra -Werror -I $(HDIR) -O3

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLXF = -lm -lmlx -lXext -lX11 -L$(MLX_DIR) -I$(MLX_DIR)

all: $(NAME)

$(ODIR)/%.o: $(CDIR)/%.c $(MLX) | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR_BONUS)/%.o: $(CDIR_BONUS)/%.c $(MLX) | $(ODIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS) $(LIBFT) $(MLX) | .bonus
	$(CC) $^ $(CFLAGS) $(MLXF) -o $(NAME)
	@rm -f .manda

$(NAME): $(OBJ) $(LIBFT) $(MLX) .manda
	$(CC) $^ $(CFLAGS) $(MLXF) -o $@
	@rm -f .bonus

.bonus:
	@touch .bonus
.manda:
	@touch .manda

### libft ###
$(LIBFT):
	make -C libft all

$(MLX): | $(MLX_DIR)
	make -C $(MLX_DIR) all

test: bonus
	./$(NAME) ./test_maps/42.fdf

vtest: bonus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) test_maps/42.fdf

### Setup ###
$(ODIR):
	mkdir -p $@

$(ODIR_BONUS):
	mkdir -p $@

init: 
	mkdir -p $(HDIR) $(CDIR) $(ODIR)

$(MLX_DIR):
	wget https://cdn.intra.42.fr/document/document/31594/minilibx-linux.tgz
	tar -xf minilibx-linux.tgz
	rm -f minilibx-linux.tgz

add_libft:
	cp -r ~/42/libft/ ./

### Clean ###
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

ffclean: fclean clean
	make -C libft fclean
	make -C minilibx-linux clean

re: fclean all

rre: ffclean all


.PHONY: clean fclean ffclean all re rre test bonus
