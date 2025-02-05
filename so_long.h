/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:19:45 by ytabia            #+#    #+#             */
/*   Updated: 2025/02/05 16:24:04 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ppos
{
	int				height;
	int				width;
}					t_ppos;

typedef struct s_epos
{
	int				height;
	int				width;
}					t_epos;

typedef struct s_enemy_move
{
	int				diff_h;
	int				diff_w;
	int				prev_h;
	int				prev_w;
	int				new_h;
	int				new_w;
	int				was_on_coin;
}					t_enemy_move;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	int				direction;
	char			**map;
	char			**copymap;
	int				coins_count;
	int				moves_count;
	void			*wall;
	int				frame_count;
	void			*floor;
	void			*coin[7];
	void			*exit;
	t_ppos			player_pos;
	t_epos			*enemy_pos;
	t_enemy_move	e_move;
	int				num_enemies;
	void			*player[12];
	void			*enemy[8];
}					t_game;

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_itoa(int n);
int					check_map_extention(char *str);
int					check_characters(char **map);
int					check_num_characters(t_game *game);
int					check_map_format(char **map);
int					check_wall(char **map);
void				player_animation(t_game *game, int i, int j);
void				coin_animation(t_game *game);
void				free_map(char **map);
void				free_all_maps(t_game *game);
int					print_err(int flag);
t_ppos				check_player_position(t_game *game);
void				floodfill(t_game *game, int raws, int cols);
int					check_map_validation(t_game *game);
void				draw_player(t_game *game, int i, int j, int frame);
int					get_coin_frame(int frame);
void				draw_map(t_game *game, int frame);
int					ft_animation(void *data);
void				load_textures(t_game *game);
void				move_player(t_game *game, int new_height, int new_width);
int					key_hook(int key_code, t_game *game);
int					read_map(char *file, t_game *game);
void				move_enemy(t_game *game);
t_epos				check_enemy_position(t_game *game);
int					ft_abs(int n);
int					check_image_array(void **image_array, int array_size);
void				calculate_direction(t_game *game, t_epos *enemy);
void				store_previous_position(t_game *game, t_epos *enemy);
void				calculate_new_position(t_game *game);
int					is_valid_position(t_game *game);
void				update_enemy_position(t_game *game, t_epos *enemy);
int					count_total_enemies(t_game *game);
void				store_enemy_positions(t_game *game, int count);
void				count_enemies(t_game *game);
int					close_window(t_game *game);
int					init_game(t_game *game);
int					init_window(t_game *game);
void				updateHeight(t_game *game, char *buf);
void				updateWidth(t_game *game, char *buf);
void				free_everything(t_game *game);

#endif