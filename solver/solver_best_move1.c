/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_best_move1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:08 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 08:18:45 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calc_best_move(t_game *game, int a_index, t_game_move *move)
{
	int	b_index;

	b_index = find_b_target_index(game, game->stack_a->elements[a_index]);
	set_r_r_move(game, a_index, b_index, move);
	improve_r_rr_move(game, a_index, b_index, move);
	improve_rr_r_move(game, a_index, b_index, move);
	improve_rr_rr_move(game, a_index, b_index, move);
}

void	execute_best_move(t_game *game)
{
	int			i;
	t_game_move	best_move;
	t_game_move	new_move;

	calc_best_move(game, 0, &best_move);
	i = 1;
	while (i < game->stack_a->content_size)
	{
		calc_best_move(game, i, &new_move);
		if (new_move.total_moves < best_move.total_moves)
			best_move = new_move;
		i++;
	}
	execute_game_move(game, &best_move);
}
