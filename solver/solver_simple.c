/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:37 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:28:38 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	solve_rotation(t_game *game)
{
	int	min_index;
	int	rotations;

	min_index = stack_find_min_index(game->stack_a);
	rotations = stack_index_distance_to_top(game->stack_a, min_index);
	if (rotations > 0)
		game_ra(game, rotations);
	else
		game_rra(game, -rotations);
	return (true);
}

bool	solve_three(t_game *game)
{
	if (stack_is_sorted(game->stack_a))
		return (true);
	if (!stack_is_sorted_rotated(game->stack_a))
		game_sa(game);
	return (solve_rotation(game));
}
