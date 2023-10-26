/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:44 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/26 12:04:31 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_game	*game_init(int total_size)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->stack_a = stack_init(total_size);
	game->stack_b = stack_init(total_size);
	if (!game->stack_a || !game->stack_b)
	{
		game_free(game);
		return (NULL);
	}
	return (game);
}

void	game_free(t_game *game)
{
	if (!game)
		return ;
	stack_free(game->stack_a);
	stack_free(game->stack_b);
	free(game);
}

bool	game_add_elements(t_game *game, int argc, char **argv)
{
	int		i;
	int		new_elem;
	bool	is_valid;

	i = 1;
	while (i < argc)
	{
		new_elem = parse_arg(argv[i], &is_valid);
		if (!is_valid)
			return (false);
		if (!game_add_element(game, new_elem))
			return (false);
		i++;
	}
	return (true);
}

bool	game_add_element(t_game *game, int new_elem)
{
	if (stack_contains(game->stack_a, new_elem))
		return (0);
	stack_push_end(game->stack_a, new_elem);
	return (1);
}

void	game_print(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("%10s %10s\n", "A", "B");
	ft_printf("---------- ----------\n");
	while (i < game->stack_a->content_size || i < game->stack_b->content_size)
	{
		if (i < game->stack_a->content_size)
			ft_printf("%10d ", game->stack_a->elements[i]);
		else
			ft_printf("%10s ", " ");
		if (i < game->stack_b->content_size)
			ft_printf("%10d \n", game->stack_b->elements[i]);
		else
			ft_printf("%10s \n", " ");
		i++;
	}
	ft_printf("---------- ----------\n");
}
