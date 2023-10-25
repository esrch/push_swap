/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:37 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 08:59:03 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solve_rotation(t_game *game)
{
	int	min_index;
	int	rotations;

	min_index = stack_find_min_index(game->stack_a);
	rotations = stack_index_distance_to_top(game->stack_a, min_index);
	if (rotations > 0)
		game_ra(game, rotations, true);
	else
		game_rra(game, -rotations, true);
}

void	solve_three(t_game *game)
{
	if (stack_is_sorted(game->stack_a))
		return ;
	if (!stack_is_sorted_rotated(game->stack_a))
		game_sa(game, true);
	solve_rotation(game);
}
