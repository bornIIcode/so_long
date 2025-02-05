/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:05:32 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/05 11:50:42 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_extention(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i >= 4)
	{
		i--;
		if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b' && str[i
				- 3] == '.')
			return (0);
		return (1);
	}
	return (1);
}

int	check_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'V')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_num_characters(t_game *game)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = -1;
	p = 0;
	e = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				p++;
			else if (game->map[i][j] == 'C')
				game->coins_count++;
			else if (game->map[i][j] == 'E')
				e++;
			j++;
		}
	}
	if (p != 1 || game->coins_count < 1 || e != 1)
		return (1);
	return (0);
}

int	check_map_format(char **map)
{
	int	i;
	int	len_1;
	int	len_2;

	i = 1;
	len_1 = 0;
	while (map[0][len_1])
		len_1++;
	while (map[i])
	{
		len_2 = 0;
		while (map[i][len_2])
			len_2++;
		if (len_1 != len_2)
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	if (!map || !map[0])
		return (1);
	len = ft_strlen(map[0]);
	j = -1;
	while (++j < len)
		if (map[0][j] != '1')
			return (1);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (1);
		i++;
	}
	j = -1;
	i--;
	while (++j < len)
		if (map[i][j] != '1')
			return (1);
	return (0);
}
