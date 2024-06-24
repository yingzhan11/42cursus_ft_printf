NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print_char.c ft_print_pointer.c ft_print_digit.c
OBJS = $(SRCS:.c=.o)

BONUS_DIR = bonus
SRCS_BONUS = ft_printf_bonus.c ft_parse_bonus.c ft_print_char_bonus.c \
				ft_print_digit_bonus.c ft_print_str_bonus.c ft_print_pointer_bonus.c \
				ft_utilities_bonus.c ft_write_bonus.c
OBJS_BONUS = $(addprefix $(BONUS_DIR)/, $(SRCS_BONUS:.c=.o))

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $@ $^

bonus: .bonus

.bonus: $(OBJS_BONUS)
	ar -rc $(NAME) $^
	@touch .bonus

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -f .bonus

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
