NAME = push_swap

LIBFT = Libft/libft.a
SRC_DIR = srcs/
OP = operations/
SORT = sorting/
UTILS = utils/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	$(SRC_DIR)push_swap.c \
		$(SRC_DIR)$(UTILS)ft_atoi_mod.c \
		$(SRC_DIR)$(UTILS)ft_check_multiples.c \
		$(SRC_DIR)$(UTILS)ft_error.c \
		$(SRC_DIR)$(UTILS)ft_free_array.c \
		$(SRC_DIR)$(UTILS)ft_free_stack.c \
		$(SRC_DIR)$(UTILS)ft_make_stack_a.c \
		$(SRC_DIR)$(UTILS)ft_set_index.c \
		$(SRC_DIR)$(UTILS)ft_sort_two.c \
		$(SRC_DIR)$(UTILS)ft_stadd_back.c \
		$(SRC_DIR)$(UTILS)ft_stlast.c \
		$(SRC_DIR)$(UTILS)ft_stnew.c \
		$(SRC_DIR)$(UTILS)ft_stsize.c \
		$(SRC_DIR)$(UTILS)ft_syntax_error.c \
		$(SRC_DIR)$(OP)push.c \
		$(SRC_DIR)$(OP)reverse_rotate.c \
		$(SRC_DIR)$(OP)rotate.c \
		$(SRC_DIR)$(OP)swap.c \
		$(SRC_DIR)$(SORT)calculate_steps.c \
		$(SRC_DIR)$(SORT)cheapest_element.c \
		$(SRC_DIR)$(SORT)execute_rotations.c \
		$(SRC_DIR)$(SORT)sorting_algorithm.c \
		$(SRC_DIR)$(SORT)sorting_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
