# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:14:41 by tmarts            #+#    #+#              #
#    Updated: 2023/05/02 22:41:53 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS = -lm
LIBFT	= ./libft
HEADERS = -I $(LIBFT)
LIBS	= $(LIBFT)/libft.a
SRC_DIR	= ./src/
SRCS	= $(addprefix $(SRC_DIR)/,	\
main.c \
push_swap_init.c \
push_swap_parsing.c \
push_swap_errors.c \
swap.c \
push.c \
rotate.c \
reverse_rotate.c \
push_swap_utils.c \
push_swap_few.c)

OBJS	= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) ${LDFLAGS}

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) fclean

fclean:	clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all, clean, fclean, re, libft
