NAME = push_swap
CHECKER_NAME = checker

GAME_SRCS = $(addprefix game/, game_utils.c game_ops1.c game_ops2.c game_ops3.c)
STACK_SRCS = $(addprefix stack/, stack_utils1.c stack_utils2.c stack_utils3.c \
	stack_ops1.c stack_ops2.c)
SOLVER_SRCS = $(addprefix solver/, solver.c solver_simple.c solver_complex.c \
	solver_best_move1.c solver_best_move2.c solver_execute_move.c)
UTILS_SRCS = utils.c
MAIN_SRCS = main.c
CHECKER_ADD_SRCS = $(addprefix checker_bonus/, checker.c)
SRCS = $(GAME_SRCS) $(STACK_SRCS) $(SOLVER_SRCS) $(UTILS_SRCS) $(MAIN_SRCS)
CHECKER_SRCS = $(GAME_SRCS) $(STACK_SRCS) $(SOLVER_SRCS) $(UTILS_SRCS) $(CHECKER_ADD_SRCS)

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
SANITIZER_FLAGS = -g3 -fsanitize=address
LIBFT_FOLDER = libft
LIBFLAGS = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_FOLDER)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFLAGS)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(MAKE) -C $(LIBFT_FOLDER)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFLAGS)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	$(MAKE) -C $(LIBFT_FOLDER) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER_NAME)
	$(MAKE) -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all bonus clean fclean re
