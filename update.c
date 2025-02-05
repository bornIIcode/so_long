/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:48:05 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/05 16:22:10 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_height(t_game *game, char *buf)
{
	game->height++;
	if (game->height >= 66)
	{
		free(buf);
		print_err(9);
		exit(1);
	}
}

void	update_width(t_game *game, char *buff)
{
	game->width = ft_strlen(game->map[0]);
	if (game->width >= 121)
	{
		free(buff);
		free_map(game->map);
		print_err(9);
		exit(1);
	}
}
