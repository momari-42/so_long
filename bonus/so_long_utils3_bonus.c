/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:13:56 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 07:48:55 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	ft_handle_if(t_data *data)
{
	if (data->dire_en == 'd'
		&& (data->map_2[data->pos_e[1] + 1][data->pos_e[0]] == '0'
		|| data->map_2[data->pos_e[1] + 1][data->pos_e[0]] == 'P'))
	{
		if (data->map_2[data->pos_e[1] + 1][data->pos_e[0]] == 'P')
			ft_handle_error(-2, "You lose :(", data);
		data->map_2[data->pos_e[1]][data->pos_e[0]] = '0';
		data->map_2[data->pos_e[1] + 1][data->pos_e[0]] = 'I';
		data->pos_e[1]++;
	}
	else if (data->dire_en == 'u'
		&& (data->map_2[data->pos_e[1] - 1][data->pos_e[0]] == '0'
		|| data->map_2[data->pos_e[1] - 1][data->pos_e[0]] == 'P'))
	{
		if (data->map_2[data->pos_e[1] - 1][data->pos_e[0]] == 'P')
			ft_handle_error(-2, "You lose :(", data);
		data->map_2[data->pos_e[1]][data->pos_e[0]] = '0';
		data->map_2[data->pos_e[1] - 1][data->pos_e[0]] = 'I';
		data->pos_e[1]--;
	}
}

static	void	ft_handle_animate(t_data *data)
{
	if (data->dire_en == 'r'
		&& (data->map_2[data->pos_e[1]][data->pos_e[0] + 1] == '0'
		|| data->map_2[data->pos_e[1]][data->pos_e[0] + 1] == 'P'))
	{
		if (data->map_2[data->pos_e[1]][data->pos_e[0] + 1] == 'P')
			ft_handle_error(-2, "You lose :(", data);
		data->map_2[data->pos_e[1]][data->pos_e[0]] = '0';
		data->map_2[data->pos_e[1]][data->pos_e[0] + 1] = 'I';
		data->pos_e[0]++;
	}
	else if (data->dire_en == 'l'
		&& (data->map_2[data->pos_e[1]][data->pos_e[0] - 1] == '0'
		|| data->map_2[data->pos_e[1]][data->pos_e[0] - 1] == 'P'))
	{
		if (data->map_2[data->pos_e[1]][data->pos_e[0] - 1] == 'P')
			ft_handle_error(-2, "You lose :(", data);
		data->map_2[data->pos_e[1]][data->pos_e[0]] = '0';
		data->map_2[data->pos_e[1]][data->pos_e[0] - 1] = 'I';
		data->pos_e[0]--;
	}
	else
		ft_handle_if(data);
}

int	animate_enemy(t_data *data)
{
	char	*directions;

	directions = "drlu";
	srand(time(NULL));
	if (data->counter == 10)
	{
		random_range(0, 3, data);
		data->dire_en = directions[data->res];
		ft_handle_animate(data);
		data->counter = 0;
	}
	else
		data->counter++;
	ft_fill_window(data);
	usleep(27000);
	data->index__ = (data->index__ + 1) % data->frames_;
	return (0);
}

void	random_range(int min, int max, t_data *data)
{
	int	ran;

	ran = data->res;
	while (data->res == ran)
		ran = rand() % (max - min + 1) + min;
	data->res = ran;
}

void	**ft_init_enemy(t_data *data)
{
	data->enemy = (void **)malloc(6 * sizeof(void *));
	if (!data->enemy)
		ft_handle_error(-4, "Error", data);
	data->enemy[0] = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/enemy1.xpm", &data->a, &data->b);
	data->enemy[1] = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/enemy2.xpm", &data->a, &data->b);
	data->enemy[2] = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/enemy3.xpm", &data->a, &data->b);
	data->enemy[3] = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/enemy4.xpm", &data->a, &data->b);
	data->enemy[4] = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/enemy5.xpm", &data->a, &data->b);
	data->enemy[5] = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/enemy6.xpm", &data->a, &data->b);
	if (!data->enemy[0] || !data->enemy[1] || !data->enemy[2]
		|| !data->enemy[3] || !data->enemy[4] || !data->enemy[5])
		ft_handle_error(-4, "Error", data);
	data->frames_ = 6;
	return (data->enemy);
}
