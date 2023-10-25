/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_best_move2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:14 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:28:16 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_b_target_index(t_game *game, int elem)
{
	int	i;
	int	placement;
	int	value;
	int	current;

	if (game->stack_b->content_size < 2)
		return (0);
	if (elem > game->stack_b->max || elem < game->stack_b->min)
		return (stack_find_max_index(game->stack_b));
	i = 0;
	while (game->stack_b->elements[i] > elem)
		i++;
	placement = i;
	value = game->stack_b->elements[i];
	while (i < game->stack_b->content_size)
	{
		current = game->stack_b->elements[i];
		if (current > value && current < elem)
		{
			value = current;
			placement = i;
		}
		i++;
	}
	return (placement);
}

void	set_r_r_move(t_game *game, int a_index, int b_index,
	t_game_move *move)
{
	(void) game;
	move->move_type = R_R;
	move->a_move_count = a_index;
	move->b_move_count = b_index;
	move->total_moves = max(a_index, b_index);
}

void	improve_r_rr_move(t_game *game, int a_index, int b_index,
	t_game_move *move)
{
	int	b_rr_distance;

	b_rr_distance = game->stack_b->content_size - b_index;
	if (a_index + b_rr_distance >= move->total_moves)
		return ;
	move->total_moves = a_index + b_rr_distance;
	move->move_type = R_RR;
	move->a_move_count = a_index;
	move->b_move_count = b_rr_distance;
}

void	improve_rr_r_move(t_game *game, int a_index, int b_index,
	t_game_move *move)
{
	int	a_rr_distance;

	a_rr_distance = game->stack_a->content_size - a_index;
	if (a_rr_distance + b_index >= move->total_moves)
		return ;
	move->total_moves = a_rr_distance + b_index;
	move->move_type = RR_R;
	move->a_move_count = a_rr_distance;
	move->b_move_count = b_index;
}

void	improve_rr_rr_move(t_game *game, int a_index, int b_index,
	t_game_move *move)
{
	int	a_rr_distance;
	int	b_rr_distance;

	a_rr_distance = game->stack_a->content_size - a_index;
	b_rr_distance = game->stack_b->content_size - b_index;
	if (max(a_rr_distance, b_rr_distance) >= move->total_moves)
		return ;
	move->total_moves = max(a_rr_distance, b_rr_distance);
	move->move_type = RR_RR;
	move->a_move_count = a_rr_distance;
	move->b_move_count = b_rr_distance;
}
