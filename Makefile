# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:01:32 by fnichola          #+#    #+#              #
#    Updated: 2022/02/04 16:56:58 by fnichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = srcs/main.c \
	   srcs/ft_stack.c \
	   srcs/ft_stack_2.c \
	   srcs/game_operations.c \
	   srcs/do_op.c \
	   srcs/push_swap.c \
	   srcs/quick_sort_a.c \
	   srcs/quick_sort_b.c \
	   srcs/find_median.c \
	   srcs/utilities.c \
	   srcs/ft_atoll.c

ifdef WITH_BONUS
endif

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -o $@ -c $<
	
$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1

$(LIBFT_LIB):
	$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) clean WITH_BONUS=1 -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
