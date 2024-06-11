# Compiler
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Library name
NAME := libftprintf.a

# Source files
SRCS := ft_printf.c \
		ft_putchar.c \
		ft_printnum.c

# Object files
OBJS := $(SRCS:.c=.o)

# Build rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Clean and remove library rule
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re bonus