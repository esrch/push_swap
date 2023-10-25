/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_execute_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:29 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 08:58:45 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_r_r(t_game *game, t_game_move *move)
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

static void	execute_r_rr(t_game *game, t_game_move *move)
{
	game_ra(game, move->a_move_count, true);
	game_rrb(game, move->b_move_count, true);
}

static void	execute_rr_r(t_game *game, t_game_move *move)
{
	game_rra(game, move->a_move_count, true);
	game_rb(game, move->b_move_count, true);
}

static void	execute_rr_rr(t_game *game, t_game_move *move)
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
	if (move->move_type == R_R)
		execute_r_r(game, move);
	else if (move->move_type == R_RR)
		execute_r_rr(game, move);
	else if (move->move_type == RR_R)
		execute_rr_r(game, move);
	else
		execute_rr_rr(game, move);
	game_pb(game, 1, true);
}
