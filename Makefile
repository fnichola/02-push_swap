# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:01:32 by fnichola          #+#    #+#              #
#    Updated: 2021/12/22 23:36:57 by fnichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRCS = srcs/main.c \
	   srcs/stack.c \
	   srcs/addl_stack_operations.c \
	   srcs/game_operations.c \
	   srcs/push_swap.c \
	   srcs/quick_sort.c \
	   srcs/find_median.c

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
