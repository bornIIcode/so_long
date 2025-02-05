/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:39:17 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/05 12:52:46 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_move_loop(t_game *game)
{
	static int	move_counter;

	move_counter++;
	if (move_counter >= 50)
	{
		move_enemy(game);
		move_counter = 0;
	}
	ft_animation(game);
	return (0);
}

int	validate_map(t_game *game, char *map)
{
	if (check_map_extention(map))
		return (print_err(0));
	if (read_map(map, game))
		return (print_err(1));
	if (check_characters(game->map))
		return (free_all_maps(game), print_err(2));
	if (check_num_characters(game))
		return (free_all_maps(game), print_err(3));
	if (check_map_format(game->map))
		return (free_all_maps(game), print_err(4));
	if (check_wall(game->map))
		return (free_all_maps(game), print_err(5));
	return (0);
}

int	setup_game_elements(t_game *game)
{
	t_ppos	player_pos;
	t_epos	enemy_pos;

	player_pos = check_player_position(game);
	enemy_pos = check_enemy_position(game);
	floodfill(game, player_pos.height, player_pos.width);
	if (check_map_validation(game))
		return (free_all_maps(game), print_err(6));
	return (0);
}

void	setup_mlx_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, close_window, game);
	mlx_loop_hook(game->mlx, enemy_move_loop, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_err(8));
	ft_memset(&game, 0, sizeof(t_game));
	if (validate_map(&game, argv[1]))
		return (free_all_maps(&game), 1);
	if (setup_game_elements(&game))
		return (1);
	if (init_game(&game))
		return (1);
	if (init_window(&game))
		return (1);
	load_textures(&game);
	count_enemies(&game);
	setup_mlx_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
