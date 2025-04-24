# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tell <ale-tell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 20:57:01 by ale-tell          #+#    #+#              #
#    Updated: 2024/11/05 15:57:11 by ale-tell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CDIR = ./src
HDIR = ./include/
CFLAGS = -O3 -Wall -Wextra -Werror -I$(HDIR)

SRC =	$(CDIR)/ft_atoi.c \
		$(CDIR)/ft_bzero.c \
		$(CDIR)/ft_isalnum.c \
		$(CDIR)/ft_isalpha.c \
		$(CDIR)/ft_isascii.c \
		$(CDIR)/ft_isdigit.c \
		$(CDIR)/ft_isprint.c \
		$(CDIR)/ft_itoa.c \
		$(CDIR)/ft_memchr.c \
		$(CDIR)/ft_memcmp.c \
		$(CDIR)/ft_memcpy.c \
		$(CDIR)/ft_memmove.c \
		$(CDIR)/ft_memset.c \
		$(CDIR)/ft_putchar_fd.c \
		$(CDIR)/ft_putendl_fd.c \
		$(CDIR)/ft_putnbr_fd.c \
		$(CDIR)/ft_putstr_fd.c \
		$(CDIR)/ft_split.c \
		$(CDIR)/ft_strchr.c \
		$(CDIR)/ft_strdup.c \
		$(CDIR)/ft_striteri.c \
		$(CDIR)/ft_strjoin.c \
		$(CDIR)/ft_strlcat.c \
		$(CDIR)/ft_strlcpy.c \
		$(CDIR)/ft_strlen.c \
		$(CDIR)/ft_strmapi.c \
		$(CDIR)/ft_strncmp.c \
		$(CDIR)/ft_strnstr.c \
		$(CDIR)/ft_strrchr.c \
		$(CDIR)/ft_strtrim.c \
		$(CDIR)/ft_substr.c \
		$(CDIR)/ft_tolower.c \
		$(CDIR)/ft_calloc.c \
		$(CDIR)/ft_toupper.c \
		$(CDIR)/ft_lstnew_bonus.c \
		$(CDIR)/ft_lstadd_front_bonus.c \
		$(CDIR)/ft_lstsize_bonus.c \
		$(CDIR)/ft_lstlast_bonus.c \
		$(CDIR)/ft_lstadd_back_bonus.c \
		$(CDIR)/ft_lstdelone_bonus.c \
		$(CDIR)/ft_lstclear_bonus.c \
		$(CDIR)/ft_lstiter_bonus.c \
		$(CDIR)/ft_lstmap_bonus.c \
		$(CDIR)/get_next_line.c \

SRC +=	$(CDIR)/ft_math/ft_max.c \
		$(CDIR)/ft_math/ft_min.c \
		$(CDIR)/ft_math/ft_abs.c \
		$(CDIR)/ft_find.c \
		$(CDIR)/ft_striter.c \
		$(CDIR)/ft_any.c \
		$(CDIR)/ft_sort.c \
		$(CDIR)/ft_swap.c \

SRC +=	$(CDIR)/ft_printf/conv_utils.c \
		$(CDIR)/ft_printf/ft_printf.c \
		$(CDIR)/ft_printf/ft_put.c \
		$(CDIR)/ft_printf/nbrlen.c \
		$(CDIR)/ft_printf/parse_arg.c \
		$(CDIR)/ft_printf/print_convs.c \


ODIR = obj

ODIRS = $(ODIR)/ft_printf \
		$(ODIR)/get_next_line \
		$(ODIR)/ft_math

OBJ = $(patsubst $(CDIR)/%.c, $(ODIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(ODIR)/%.o: $(CDIR)/%.c | $(ODIR) $(ODIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIRS):
	mkdir -p $@ $(ODIRS)

$(ODIR):
	mkdir -p $@ $(ODIR)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
