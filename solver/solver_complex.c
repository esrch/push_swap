/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:21 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 08:59:36 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	fill_b(t_game *game)
{
	while (game->stack_a->content_size > 3)
	{
		execute_best_move(game);
		if (stack_is_sorted(game->stack_a))
			return ;
		if (stack_is_sorted_rotated(game->stack_a))
		{
			solve_rotation(game);
			return ;
		}
	}
}

static void	bring_b_max_to_top(t_game *game)
{
	int	max_index;
	int	rotations;

	max_index = stack_find_max_index(game->stack_b);
	rotations = stack_index_distance_to_top(game->stack_b, max_index);
	if (rotations > 0)
		game_rb(game, rotations, true);
	else
		game_rrb(game, -rotations, true);
}

static void	refill_a(t_game *game)
{
	if (game->stack_a->elements[0] > game->stack_b->elements[0])
	{
		game_pa(game, game->stack_b->content_size, true);
		return ;
	}
	if (stack_last(game->stack_a) > game->stack_b->elements[0])
		game_rra(game, 1, true);
	while (game->stack_b->content_size > 0)
	{
		while (stack_last(game->stack_a) > game->stack_b->elements[0]
			&& stack_last(game->stack_a) < game->stack_a->elements[0])
			game_rra(game, 1, true);
		game_pa(game, 1, true);
	}
	solve_rotation(game);
}

void	solve_complex(t_game *game)
{
	fill_b(game);
	solve_three(game);
	bring_b_max_to_top(game);
	refill_a(game);
}
