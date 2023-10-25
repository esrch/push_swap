/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:30 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 08:53:04 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	game_ra(t_game *game, int times, bool print)
{
	stack_rotate(game->stack_a, times);
	if (print)
		print_mult("ra", times);
}

void	game_rb(t_game *game, int times, bool print)
{
	stack_rotate(game->stack_b, times);
	if (print)
		print_mult("rb", times);
}

void	game_rr(t_game *game, int times, bool print)
{
	stack_rotate(game->stack_a, times);
	stack_rotate(game->stack_b, times);
	if (print)
		print_mult("rr", times);
}
