/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:47:46 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/04 17:31:59 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_total_enemies(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'V')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	store_enemy_positions(t_game *game, int count)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (game->map[i] && index < count)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'V')
			{
				game->enemy_pos[index].height = i;
				game->enemy_pos[index].width = j;
				index++;
			}
			j++;
		}
		i++;
	}
}

void	count_enemies(t_game *game)
{
	int	count;

	count = count_total_enemies(game);
	if (count == 0)
	{
		game->enemy_pos = NULL;
		return ;
	}
	game->num_enemies = count;
	game->enemy_pos = malloc(sizeof(t_epos) * count);
	if (!game->enemy_pos)
		return ;
	store_enemy_positions(game, count);
}

int	get_coin_frame(int frame)
{
	static int	x;

	if (frame % 30 == 0)
	{
		x++;
		if (x == 7)
			x = 0;
	}
	return (x);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
