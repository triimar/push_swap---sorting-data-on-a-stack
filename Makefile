# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:14:41 by tmarts            #+#    #+#              #
#    Updated: 2023/05/15 21:55:17 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_B = checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3
LDFLAGS = -lm
LDFLAGS += -fsanitize=address -g3
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
push_swap_few.c \
push_swap_many.c \
push_swap.c)

SRC_B_DIR = ./bonus/
SRCS_B	= $(addprefix $(SRC_B_DIR)/,\
main.c \
checker_init.c \
checker_parsing.c \
checker_errors.c \
swap.c \
push.c \
rotate.c \
reverse_rotate.c \
checker_utils.c \
checker.c)

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

all: libft $(NAME)

bonus: $(NAME_B)

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) ${LDFLAGS}

$(NAME_B): $(OBJS_B)
	@$(CC) $(OBJS_B) $(LIBS) $(HEADERS) -o $(NAME_B) ${LDFLAGS}

clean:
	@rm -f $(OBJS) $(OBJS_B)
	@$(MAKE) -C $(LIBFT) fclean

fclean:	clean
	@rm -f $(NAME) $(NAME_B)
	
re: fclean all

.PHONY: all, clean, fclean, re, libft
