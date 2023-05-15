# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:14:41 by tmarts            #+#    #+#              #
#    Updated: 2023/05/15 18:52:58 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3
LDFLAGS = -lm
LDFLAGS += -fsanitize=address -g3
LIBFT	= ../libft
HEADERS = -I $(LIBFT)
LIBS	= $(LIBFT)/libft.a
SRCS	= main.c \
checker_init.c \
checker_parsing.c \
checker_errors.c \
swap.c \
push.c \
rotate.c \
reverse_rotate.c \
checker_utils.c \
checker.c


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
