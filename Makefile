NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBFT	= libft/libft.a

SRCS	= src/main.c src/flags.c src/parse.c src/error.c src/normalize.c src/stack.c src/disorder.c

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -I. -Ilibft -c $< -o $@

clean :
	@make -C libft clean
	@$(RM) $(OBJS)

fclean : clean
	@make -C libft fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
