/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:32:29 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/04 17:32:13 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_game *game, int raws, int cols)
{
	if (game->height < 0 || game->height < raws || game->width < 0
		|| game->width < cols)
		return ;
	if (game->copymap[raws][cols] == '1' || game->copymap[raws][cols] == 'E'
		|| game->copymap[raws][cols] == 'X')
	{
		if (game->copymap[raws][cols] == 'E')
			game->copymap[raws][cols] = '1';
		return ;
	}
	game->copymap[raws][cols] = 'X';
	floodfill(game, raws + 1, cols);
	floodfill(game, raws - 1, cols);
	floodfill(game, raws, cols + 1);
	floodfill(game, raws, cols - 1);
}

int	check_map_validation(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->copymap[i])
	{
		j = 0;
		while (game->copymap[i][j])
		{
			if (game->copymap[i][j] == 'E' || game->copymap[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_ppos	check_player_position(t_game *game)
{
	int		i;
	int		j;
	t_ppos	player_pos;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				player_pos.height = i;
				player_pos.width = j;
				break ;
			}
			j++;
		}
		i++;
	}
	game->player_pos = player_pos;
	return (player_pos);
}

t_epos	check_enemy_position(t_game *game)
{
	int		i;
	int		j;
	t_epos	enemy_pos;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'V')
			{
				enemy_pos.height = i;
				enemy_pos.width = j;
			}
			j++;
		}
		i++;
	}
	game->enemy_pos = &enemy_pos;
	return (enemy_pos);
}

int	ft_animation(void *data)
{
	t_game		*game;
	static int	frame;

	game = (t_game *)data;
	frame++;
	if (frame == 1000)
		frame = 0;
	draw_map(game, frame);
	return (0);
}
