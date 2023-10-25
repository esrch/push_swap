/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:30 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:27:32 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	game_ra(t_game *game, int times)
{
	stack_rotate(game->stack_a, times);
	print_mult("ra", times);
}

void	game_rb(t_game *game, int times)
{
	stack_rotate(game->stack_b, times);
	print_mult("rb", times);
}

void	game_rr(t_game *game, int times)
{
	stack_rotate(game->stack_a, times);
	stack_rotate(game->stack_b, times);
	print_mult("rr", times);
}
