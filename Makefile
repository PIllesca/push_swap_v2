# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 12:19:45 by pillesca          #+#    #+#              #
#    Updated: 2025/04/24 19:13:39 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTSRC = libft.a
LIBFTDIR = ./lib/libft

SRC = main.c push_swap.c aux_stack.c chk_args.c aux_swap.c aux_sort.c
SRC += aux_rotate.c aux_reverse.c aux_push.c aux_find.c aux_best_ab.c
SRC += aux_best_ba.c aux_apply.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

AR = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: makelib $(NAME)

makelib:
	make -C $(LIBFTDIR)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTDIR)/$(LIBFTSRC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all, clean, fclean, re