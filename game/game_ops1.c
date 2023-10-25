/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ops1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:22 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 07:07:31 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	game_sa(t_game *game)
{
	stack_swap(game->stack_a);
	print_mult("sa", 1);
}

void	game_sb(t_game *game)
{
	stack_swap(game->stack_b);
	print_mult("sb", 1);
}

void	game_ss(t_game *game)
{
	stack_swap(game->stack_a);
	stack_swap(game->stack_b);
	print_mult("ss", 1);
}

void	game_pa(t_game *game, int times)
{
	int	i;
	int	elem;

	i = 0;
	while (i < times)
	{
		elem = stack_pop(game->stack_b);
		stack_push(game->stack_a, elem);
		i++;
	}
	print_mult("pa", times);
}

void	game_pb(t_game *game, int times)
{
	int	i;
	int	elem;

	i = 0;
	while (i < times)
	{
		elem = stack_pop(game->stack_a);
		stack_push(game->stack_b, elem);
		i++;
	}
	print_mult("pb", times);
}
