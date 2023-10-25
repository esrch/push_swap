/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:21 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:28:22 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	fill_b(t_game *game)
{
	while (game->stack_a->content_size > 3)
	{
		execute_best_move(game);
		if (stack_is_sorted(game->stack_a))
			break ;
		if (stack_is_sorted_rotated(game->stack_a))
		{
			solve_rotation(game);
			break ;
		}
	}
	return (true);
}

static bool	bring_b_max_to_top(t_game *game)
{
	int	max_index;
	int	rotations;

	max_index = stack_find_max_index(game->stack_b);
	rotations = stack_index_distance_to_top(game->stack_b, max_index);
	if (rotations > 0)
		game_rb(game, rotations);
	else
		game_rrb(game, -rotations);
	return (true);
}

static bool	refill_a(t_game *game)
{
	if (game->stack_a->elements[0] > game->stack_b->elements[0])
	{
		game_pa(game, game->stack_b->content_size);
		return (true);
	}
	if (stack_last(game->stack_a) > game->stack_b->elements[0])
		game_rra(game, 1);
	while (game->stack_b->content_size > 0)
	{
		while (stack_last(game->stack_a) > game->stack_b->elements[0]
			&& stack_last(game->stack_a) < game->stack_a->elements[0])
			game_rra(game, 1);
		game_pa(game, 1);
	}
	return (solve_rotation(game));
}

bool	solve_complex(t_game *game)
{
	if (!fill_b(game))
		return (false);
	if (!solve_three(game))
		return (false);
	if (!bring_b_max_to_top(game))
		return (false);
	if (!refill_a(game))
		return (false);
	return (true);
}
