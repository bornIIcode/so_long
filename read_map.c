/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:12:35 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/05 16:23:46 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	process_map_data(char *buff, t_game *game)
{
	game->map = ft_split(buff, '\n');
	update_width(game, buff);
	game->copymap = ft_split(buff, '\n');
}

int	read_map(char *file, t_game *game)
{
	char	*buff;
	char	*line;
	char	*tmp;
	int		fd;

	buff = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n')
			return (free(line), free(buff), 1);
		tmp = buff;
		buff = ft_strjoin(buff, line);
		free(tmp);
		free(line);
		update_height(game, buff);
	}
	if (!buff)
		return (1);
	return (process_map_data(buff, game), free(buff), 0);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	return (0);
}

int	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "so_long");
	if (!game->win)
		return (1);
	return (0);
}

int	check_image_array(void **image_array, int array_size)
{
	int	x;

	x = 0;
	while (x < array_size)
	{
		if (!image_array[x])
		{
			print_err(7);
			exit(1);
		}
		x++;
	}
	return (0);
}
