/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:26:39 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:34:55 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		return (1);
	game = game_init(argc - 1);
	if (!game)
	{
		print_error();
		return (1);
	}
	if (!game_add_elements(game, argc, argv))
	{
		print_error();
		game_free(game);
		return (1);
	}
	if (!solve_game(game))
		print_error();
}
