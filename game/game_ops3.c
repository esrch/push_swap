/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ops3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:37 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:27:38 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	game_rra(t_game *game, int times)
{
	stack_rev_rotate(game->stack_a, times);
	print_mult("rra", times);
}

void	game_rrb(t_game *game, int times)
{
	stack_rev_rotate(game->stack_b, times);
	print_mult("rrb", times);
}

void	game_rrr(t_game *game, int times)
{
	stack_rev_rotate(game->stack_a, times);
	stack_rev_rotate(game->stack_b, times);
	print_mult("rrr", times);
}
