/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:20:36 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/03 18:20:37 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_game *game, int i, int j)
{
	game->player[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_closed.xpm", &i, &j);
	game->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_semi_right.xpm", &i, &j);
	game->player[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_open_right.xpm", &i, &j);
	game->player[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_closed.xpm", &i, &j);
	game->player[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_semi_left.xpm", &i, &j);
	game->player[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_open_left.xpm", &i, &j);
	game->player[6] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_closed.xpm", &i, &j);
	game->player[7] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_semi_up.xpm", &i, &j);
	game->player[8] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_open_up.xpm", &i, &j);
	game->player[9] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_closed.xpm", &i, &j);
	game->player[10] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_semi_down.xpm", &i, &j);
	game->player[11] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pac_open_down.xpm", &i, &j);
	check_image_array(game->player, 12);
}

void	coin_animation(t_game *game)
{
	int	i;
	int	j;

	game->coin[0] = mlx_xpm_file_to_image(game->mlx, "./textures/pacdot0.xpm",
			&i, &j);
	game->coin[1] = mlx_xpm_file_to_image(game->mlx, "./textures/pacdot1.xpm",
			&i, &j);
	game->coin[2] = mlx_xpm_file_to_image(game->mlx, "./textures/pacdot2.xpm",
			&i, &j);
	game->coin[3] = mlx_xpm_file_to_image(game->mlx, "./textures/pacdot3.xpm",
			&i, &j);
	game->coin[4] = mlx_xpm_file_to_image(game->mlx, "./textures/pacdot4.xpm",
			&i, &j);
	game->coin[5] = mlx_xpm_file_to_image(game->mlx, "./textures/pacdot5.xpm",
			&i, &j);
	game->coin[6] = mlx_xpm_file_to_image(game->mlx,
			"./textures/pacdot_food.xpm", &i, &j);
	check_image_array(game->coin, 7);
}

void	enemy_animation(t_game *game)
{
	int	i;
	int	j;

	game->enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_right1.xpm", &i, &j);
	game->enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_left1.xpm", &i, &j);
	game->enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_left2.xpm", &i, &j);
	game->enemy[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_right2.xpm", &i, &j);
	game->enemy[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_up1.xpm", &i, &j);
	game->enemy[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_down1.xpm", &i, &j);
	game->enemy[6] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_down2.xpm", &i, &j);
	game->enemy[7] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_up2.xpm", &i, &j);
	check_image_array(game->enemy, 8);
}

void	enemy_below_coin_animation(t_game *game)
{
	int	i;
	int	j;

	game->enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_right1.xpm", &i, &j);
	game->enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_left1.xpm", &i, &j);
	game->enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_left2.xpm", &i, &j);
	game->enemy[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_right2.xpm", &i, &j);
	game->enemy[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_up1.xpm", &i, &j);
	game->enemy[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_down1.xpm", &i, &j);
	game->enemy[6] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_down2.xpm", &i, &j);
	game->enemy[7] = mlx_xpm_file_to_image(game->mlx,
			"./textures/ghost_up2.xpm", &i, &j);
	check_image_array(game->enemy, 8);
}

void	load_textures(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	player_animation(game, i, j);
	coin_animation(game);
	enemy_animation(game);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall1.xpm", &i,
			&j);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm", &i,
			&j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &i,
			&j);
	if (!game->wall || !game->floor || !game->exit)
	{
		print_err(7);
		exit(1);
	}
}
