/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:26:54 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/26 12:04:14 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*elements;
	int	content_size;
	int	total_size;
	int	max;
	int	min;
}	t_stack;

typedef struct s_game
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_game;

typedef enum e_move_type
{
	RA_RB,
	RA_RRB,
	RRA_RB,
	RRA_RRB
}	t_move_type;

typedef struct s_game_move
{
	int			total_moves;
	t_move_type	move_type;
	int			a_move_count;
	int			b_move_count;
}	t_game_move;

// Stack
t_stack	*stack_init(int total_size);
void	stack_free(t_stack *stack);
bool	stack_contains(t_stack *stack, int elem);
bool	stack_is_sorted(t_stack *stack);
bool	stack_is_sorted_rotated(t_stack *stack);
int		stack_find_index(t_stack *stack, int elem, bool *is_found);
int		stack_find_min_index(t_stack *stack);
int		stack_find_max_index(t_stack *stack);
int		stack_last(t_stack *stack);
int		stack_next_index(t_stack *stack, int index);
void	stack_update_min_max(t_stack *stack, int elem);
void	stack_shift_left(t_stack *stack);
void	stack_shift_right(t_stack *stack);
int		stack_index_distance_to_top(t_stack *stack, int index);

// Stack operations
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack, int times);
void	stack_rev_rotate(t_stack *stack, int times);
void	stack_push(t_stack *stack, int new_elem);
int		stack_pop(t_stack *stack);
void	stack_push_end(t_stack *stack, int elem);

// Game
t_game	*game_init(int total_size);
void	game_free(t_game *game);
bool	game_add_elements(t_game *game, int argc, char **argv);
bool	game_add_element(t_game *game, int new_elem);
void	game_print(t_game *game);

// Game ops
void	game_sa(t_game *game, bool print);
void	game_sb(t_game *game, bool print);
void	game_ss(t_game *game, bool print);
void	game_pa(t_game *game, int times, bool print);
void	game_pb(t_game *game, int times, bool print);
void	game_ra(t_game *game, int times, bool print);
void	game_rb(t_game *game, int times, bool print);
void	game_rr(t_game *game, int times, bool print);
void	game_rra(t_game *game, int times, bool print);
void	game_rrb(t_game *game, int times, bool print);
void	game_rrr(t_game *game, int times, bool print);

// Solver
void	solve_game(t_game *game);
void	solve_three(t_game *game);
void	solve_complex(t_game *game);
void	solve_rotation(t_game *game);
int		find_b_target_index(t_game *game, int elem);
void	set_ra_rb_move(t_game *game, int a_index, int b_index,
			t_game_move *move);
void	improve_ra_rrb_move(t_game *game, int a_index, int b_index,
			t_game_move *move);
void	improve_rra_rb_move(t_game *game, int a_index, int b_index,
			t_game_move *move);
void	improve_rra_rrb_move(t_game *game, int a_index, int b_index,
			t_game_move *move);
void	execute_best_move(t_game *game);
void	execute_game_move(t_game *game, t_game_move *move);

// Utils
int		parse_arg(char *num_str, bool *is_valid_num);
void	print_error(void);
void	print_mult(char *str, size_t times);
int		min(int a, int b);
int		max(int a, int b);

#endif
