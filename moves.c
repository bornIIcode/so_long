/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:40:41 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/04 19:07:13 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_game *game)
{
	game->moves_count = game->moves_count + 1;
	ft_printf("moves %d \n", game->moves_count);
	ft_printf("\033[1;32mYOU WON\n\033[0m");
	free_everything(game);
	exit(1);
}

void	move_player(t_game *game, int new_height, int new_width)
{
	int		new_pos_h;
	int		new_pos_w;
	char	new_pos;

	new_pos_h = game->player_pos.height + new_height;
	new_pos_w = game->player_pos.width + new_width;
	new_pos = game->map[new_pos_h][new_pos_w];
	if (new_pos == '1')
		return ;
	if (new_pos == 'C')
		game->coins_count--;
	if (new_pos == 'E')
	{
		if (game->coins_count == 0)
			win_game(game);
		else
			return ;
	}
	game->map[game->player_pos.height][game->player_pos.width] = '0';
	game->map[new_pos_h][new_pos_w] = 'P';
	game->moves_count++;
	ft_printf("moves %d \n", game->moves_count);
	game->player_pos.height = new_pos_h;
	game->player_pos.width = new_pos_w;
}

void	handle_movement(t_game *game)
{
	if (game->map[game->e_move.new_h][game->e_move.new_w] == 'P')
	{
		ft_printf("\033[1;31mGAME OVER\n\033[0m");
		free_everything(game);
		exit(0);
	}
	if (game->e_move.was_on_coin)
		game->map[game->e_move.prev_h][game->e_move.prev_w] = 'C';
	else
		game->map[game->e_move.prev_h][game->e_move.prev_w] = '0';
	if (game->map[game->e_move.new_h][game->e_move.new_w] == 'C')
		game->map[game->e_move.new_h][game->e_move.new_w] = 'Z';
	else if (game->map[game->e_move.new_h][game->e_move.new_w] != 'V')
		game->map[game->e_move.new_h][game->e_move.new_w] = 'V';
}

void	move_enemy(t_game *game)
{
	int		i;
	t_epos	*enemy;

	if (!game || !game->enemy_pos)
		return ;
	i = 0;
	while (i < game->num_enemies)
	{
		enemy = &game->enemy_pos[i];
		calculate_direction(game, enemy);
		store_previous_position(game, enemy);
		calculate_new_position(game);
		if (!is_valid_position(game))
		{
			i++;
			continue ;
		}
		handle_movement(game);
		update_enemy_position(game, enemy);
		i++;
	}
}

int	key_hook(int key_code, t_game *game)
{
	if (key_code == 65307)
		free_everything(game);
	else if (key_code == 119)
	{
		move_player(game, -1, 0);
		game->direction = 2;
	}
	else if (key_code == 115)
	{
		move_player(game, 1, 0);
		game->direction = 3;
	}
	else if (key_code == 97)
	{
		move_player(game, 0, -1);
		game->direction = 1;
	}
	else if (key_code == 100)
	{
		move_player(game, 0, 1);
		game->direction = 0;
	}
	return (0);
}
