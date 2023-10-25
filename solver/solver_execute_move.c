/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_execute_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:29 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 12:40:10 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_ra_rb(t_game *game, t_game_move *move)
{
	while (move->a_move_count && move->b_move_count)
	{
		game_rr(game, 1, true);
		move->a_move_count--;
		move->b_move_count--;
	}
	game_ra(game, move->a_move_count, true);
	game_rb(game, move->b_move_count, true);
}

static void	execute_ra_rrb(t_game *game, t_game_move *move)
{
	game_ra(game, move->a_move_count, true);
	game_rrb(game, move->b_move_count, true);
}

static void	execute_rra_rb(t_game *game, t_game_move *move)
{
	game_rra(game, move->a_move_count, true);
	game_rb(game, move->b_move_count, true);
}

static void	execute_rra_rrb(t_game *game, t_game_move *move)
{
	while (move->a_move_count && move->b_move_count)
	{
		game_rrr(game, 1, true);
		move->a_move_count--;
		move->b_move_count--;
	}
	game_rra(game, move->a_move_count, true);
	game_rrb(game, move->b_move_count, true);
}

void	execute_game_move(t_game *game, t_game_move *move)
{
	if (move->move_type == RA_RB)
		execute_ra_rb(game, move);
	else if (move->move_type == RA_RRB)
		execute_ra_rrb(game, move);
	else if (move->move_type == RRA_RB)
		execute_rra_rb(game, move);
	else
		execute_rra_rrb(game, move);
	game_pb(game, 1, true);
}
