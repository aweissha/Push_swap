NAME = push_swap

# Directories
LIBFT = ./libft.a
SRC_DIR = srcs/

# Compilation and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Source files
SRCS =	$(SRC_DIR)ft_check_multiples.c \
		$(SRC_DIR)ft_error.c \
		$(SRC_DIR)ft_free_array.c \
		$(SRC_DIR)ft_free_stack.c \
		$(SRC_DIR)ft_make_stack_a.c \
		$(SRC_DIR)ft_stadd_back.c \
		$(SRC_DIR)ft_stlast.c \
		$(SRC_DIR)ft_stnew.c \
		$(SRC_DIR)push_swap.c \

OBJS = $(SRCS:.c=.o)

# Rules

all: $(NAME);

$(NAME) : $(OBJS)
	# $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
