/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:28:03 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	solve_game(t_game *game)
{
	if (stack_is_sorted(game->stack_a))
		return (1);
	if (stack_is_sorted_rotated(game->stack_a))
		return (solve_rotation(game));
	if (game->stack_a->content_size == 3)
		return (solve_three(game));
	return (solve_complex(game));
}
