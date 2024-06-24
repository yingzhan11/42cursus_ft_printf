# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 12:53:21 by yzhan             #+#    #+#              #
#    Updated: 2024/05/17 12:53:23 by yzhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf_bonus.c ft_parse_bonus.c ft_print_char_bonus.c \
		ft_print_digit_bonus.c ft_print_str_bonus.c ft_print_pointer_bonus.c \
		ft_utilities_bonus.c ft_write_bonus.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $@ $^

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -f .bonus

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test bonus

