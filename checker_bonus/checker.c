/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:50:55 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 19:28:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	process_instr(t_game *game, char *instr)
{
	if (!ft_strncmp(instr, "sa\n", 3))
		return (game_sa(game));
	if (!ft_strncmp(instr, "sb\n", 3))
		return (game_sb(game));
	if (!ft_strncmp(instr, "ss\n", 3))
		return (game_ss(game));
	if (!ft_strncmp(instr, "pa\n", 3))
		return (game_pa(game, 1));
	if (!ft_strncmp(instr, "pb\n", 3))
		return (game_pb(game, 1));
	if (!ft_strncmp(instr, "ra\n", 3))
		return (game_ra(game, 1));
	if (!ft_strncmp(instr, "rb\n", 3))
		return (game_rb(game, 1));
	if (!ft_strncmp(instr, "rr\n", 3))
		return (game_rr(game, 1));
	if (!ft_strncmp(instr, "rra\n", 4))
		return (game_rra(game, 1));
	if (!ft_strncmp(instr, "rrb\n", 4))
		return (game_rrb(game, 1));
	if (!ft_strncmp(instr, "rrr\n", 4))
		return (game_rrr(game, 1));
	return (false);
}

static bool	process_lines(t_game *game)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!process_instr(game, line))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(0);
	}
}

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
	if (!process_lines(game))
	{
		print_error();
		game_free(game);
		return (1);
	}
	if (stack_is_sorted(game->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
