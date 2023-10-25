/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ops1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:22 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/25 08:51:57 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	game_sa(t_game *game, bool print)
{
	stack_swap(game->stack_a);
	if (print)
		print_mult("sa", 1);
}

void	game_sb(t_game *game, bool print)
{
	stack_swap(game->stack_b);
	if (print)
		print_mult("sb", 1);
}

void	game_ss(t_game *game, bool print)
{
	stack_swap(game->stack_a);
	stack_swap(game->stack_b);
	if (print)
		print_mult("ss", 1);
}

void	game_pa(t_game *game, int times, bool print)
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
	if (print)
		print_mult("pa", times);
}

void	game_pb(t_game *game, int times, bool print)
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
	if (print)
		print_mult("pb", times);
}
