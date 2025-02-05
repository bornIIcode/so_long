/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:02:01 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/04 17:29:28 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game, int i, int j, int frame)
{
	static int	x;
	int			sprite_index;

	if (frame % 20 == 0)
	{
		x++;
		if (x == 3)
			x = 0;
	}
	sprite_index = x + (game->direction * 3);
	mlx_put_image_to_window(game->mlx, game->win, game->player[sprite_index], j
		* TILE_SIZE, i * TILE_SIZE);
}

void	draw_enemy(t_game *game, int i, int j, int frame)
{
	static int	x;
	int			sprite_index;

	if (!game || !game->map || i < 0 || j < 0 || i >= game->height
		|| j >= game->width)
		return ;
	if (frame % 70 == 0)
	{
		x++;
		if (x == 7)
			x = 0;
	}
	sprite_index = x;
	if (sprite_index < 0 || sprite_index >= 8)
		sprite_index = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->enemy[sprite_index], j
		* TILE_SIZE, i * TILE_SIZE);
}

void	draw_enemy_below_coin(t_game *game, int i, int j, int frame)
{
	static int	x;
	int			sprite_index;

	if (!game || !game->map || i < 0 || j < 0 || i >= game->height
		|| j >= game->width)
		return ;
	if (frame % 20 == 0)
	{
		x++;
		if (x == 7)
			x = 0;
	}
	sprite_index = x;
	if (sprite_index < 0 || sprite_index >= 8)
		sprite_index = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->enemy[sprite_index], j
		* TILE_SIZE, i * TILE_SIZE);
}

void	draw_tile(t_game *game, char tile, t_ppos pos, int frame)
{
	int	coin_frame;

	coin_frame = get_coin_frame(frame);
	if (tile == 'P')
		draw_player(game, pos.height, pos.width, frame);
	else if (tile == 'V')
		draw_enemy(game, pos.height, pos.width, frame);
	else if (tile == 'Z')
		draw_enemy_below_coin(game, pos.height, pos.width, frame);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor, pos.width
			* TILE_SIZE, pos.height * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin[coin_frame],
			pos.width * TILE_SIZE, pos.height * TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, pos.width
			* TILE_SIZE, pos.height * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, pos.width
			* TILE_SIZE, pos.height * TILE_SIZE);
}

void	draw_map(t_game *game, int frame)
{
	t_ppos	pos;

	pos.height = 0;
	while (game->map[pos.height])
	{
		pos.width = 0;
		while (game->map[pos.height][pos.width])
		{
			draw_tile(game, game->map[pos.height][pos.width], pos, frame);
			pos.width++;
		}
		pos.height++;
	}
}
