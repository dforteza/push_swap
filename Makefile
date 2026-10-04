NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

GREEN	= \033[1;32m
RESET	= \033[0m

LIBFT	= libft/libft.a

SRCS  = src/main.c src/flags.c src/parse.c src/error.c \
        src/prepare.c src/bench.c src/stack.c src/stack_utils.c \
        src/ops/swap_ops.c src/ops/push_ops.c src/ops/rotate_ops.c \
        src/ops/reverse_rotate_ops.c src/ops/ops_utils.c \
        src/sort/sort_utils.c src/sort/selection_sort.c \
        src/sort/chunk_sort.c src/sort/small_sort.c src/sort/insertion_sort.c \
        src/sort/quicksort.c src/sort/quicksort_utils.c \

OBJS	= $(SRCS:.c=.o)

all : banner $(NAME)

banner :
	@printf "$(GREEN)██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ $(RESET)\n"
	@printf "$(GREEN)██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗$(RESET)\n"
	@printf "$(GREEN)██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝$(RESET)\n"
	@printf "$(GREEN)██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ $(RESET)\n"
	@printf "$(GREEN)██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     $(RESET)\n"
	@printf "$(GREEN)╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     $(RESET)\n"

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C libft

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -I. -Ilibft -c $< -o $@

clean :
	@make -C libft clean
	@$(RM) $(OBJS)

fclean : clean
	@make -C libft fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all banner clean fclean re
