/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:47:05 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/04 17:31:51 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_direction(t_game *game, t_epos *enemy)
{
	game->e_move.diff_h = game->player_pos.height - enemy->height;
	game->e_move.diff_w = game->player_pos.width - enemy->width;
}

void	store_previous_position(t_game *game, t_epos *enemy)
{
	game->e_move.prev_h = enemy->height;
	game->e_move.prev_w = enemy->width;
	game->e_move.was_on_coin = (game->map[enemy->height][enemy->width] == 'Z');
}

void	calculate_new_position(t_game *game)
{
	game->e_move.new_h = game->e_move.prev_h;
	game->e_move.new_w = game->e_move.prev_w;
	if (ft_abs(game->e_move.diff_h) > ft_abs(game->e_move.diff_w))
	{
		if (game->e_move.diff_h > 0)
			game->e_move.new_h++;
		else if (game->e_move.diff_h < 0)
			game->e_move.new_h--;
	}
	else
	{
		if (game->e_move.diff_w > 0)
			game->e_move.new_w++;
		else if (game->e_move.diff_w < 0)
			game->e_move.new_w--;
	}
}

int	is_valid_position(t_game *game)
{
	if (game->e_move.new_h < 0 || game->e_move.new_w < 0
		|| game->e_move.new_h >= game->height
		|| game->e_move.new_w >= game->width)
		return (0);
	if (game->map[game->e_move.new_h][game->e_move.new_w] == '1'
		|| game->map[game->e_move.new_h][game->e_move.new_w] == 'E'
		|| game->map[game->e_move.new_h][game->e_move.new_w] == 'Z'
		|| game->map[game->e_move.new_h][game->e_move.new_w] == 'V')
		return (0);
	return (1);
}

void	update_enemy_position(t_game *game, t_epos *enemy)
{
	enemy->height = game->e_move.new_h;
	enemy->width = game->e_move.new_w;
}
