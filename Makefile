# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 12:19:45 by pillesca          #+#    #+#              #
#    Updated: 2025/03/08 12:21:22 by pillesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTSRC = libft.a
LIBFTDIR = ./lib/libft

SRC += main.c push_swap.c aux_stack.c chk_args.c

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