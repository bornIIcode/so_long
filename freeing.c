/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:32:46 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/05 16:24:54 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all_maps(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->copymap)
		free_map(game->copymap);
}

void	free_everything(t_game *game)
{
	int	i;

	free_all_maps(game);
	free(game->enemy_pos);
	i = 0;
	while (i < 12)
		mlx_destroy_image(game->mlx, game->player[i++]);
	i = 0;
	while (i < 7)
		mlx_destroy_image(game->mlx, game->coin[i++]);
	i = 0;
	while (i < 8)
		mlx_destroy_image(game->mlx, game->enemy[i++]);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	print_err(int flag)
{
	if (flag == 0)
		write(2, "Error: map extention not correct\n", 33);
	else if (flag == 1)
		write(2, "Error: unable to read map\n", 26);
	else if (flag == 2)
		write(2, "Error: invalid characters\n", 26);
	else if (flag == 3)
		write(2, "Error: number characters not correct\n", 37);
	else if (flag == 4)
		write(2, "Error: map format not correct\n", 30);
	else if (flag == 5)
		write(2, "Error: wall map not correct\n", 28);
	else if (flag == 6)
		write(2, "Error: map not valid\n", 21);
	else if (flag == 7)
		write(2, "Error: failed to load textures\n", 31);
	else if (flag == 8)
		write(2, "Error: messing argument\n", 24);
	else if (flag == 9)
		write(2, "Error: invalid dimensions\n", 26);
	return (1);
}

int	close_window(t_game *game)
{
	free_everything(game);
	exit(0);
}
