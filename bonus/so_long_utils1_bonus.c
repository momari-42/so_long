/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:13:51 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 11:20:04 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_manage_so_long(t_data *data, char *file)
{
	ft_check_extention(file, data);
	ft_memset(data, 0, sizeof(data));
	data->dire_en = 'r';
	data->counter = 0;
	data->map_1 = ft_read_map(file, data);
	data->map_2 = ft_read_map(file, data);
	ft_is_valid(data);
}

void	ft_check_extention(char *file, t_data *data)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	while (file[i] && file[i] != '.')
		i--;
	if (file[i++] != '.' || file[i++] != 'b'
		|| file[i++] != 'e' || file[i++] != 'r'
		|| file[i] != '\0')
		ft_handle_error(-1, "Error", data);
}

static void	ft_check_if(int x, int y, t_data *data)
{
	if (data->map_2[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_pt, data->win_pt,
			data->collec, x * 50, y * 50);
	else if (data->map_2[y][x] == 'E')
	{
		if (data->check_d == -1)
			mlx_put_image_to_window(data->mlx_pt, data->win_pt,
				data->door_o, x * 50, y * 50);
		else
			mlx_put_image_to_window(data->mlx_pt, data->win_pt,
				data->door_c, x * 50, y * 50);
	}
	else if (data->map_2[y][x] == 'I')
		mlx_put_image_to_window(data->mlx_pt, data->win_pt,
			data->enemy[data->index__], x * 50, y * 50);
}

static void	ft_check_for_fill(int x, int y, t_data *data)
{
	if (data->map_2[y][x] == '1')
		mlx_put_image_to_window(data->mlx_pt, data->win_pt,
			data->wall__, x * 50, y * 50);
	else if (data->map_2[y][x] == '0')
		mlx_put_image_to_window(data->mlx_pt, data->win_pt,
			data->floor_, x * 50, y * 50);
	else if (data->map_2[y][x] == 'P')
	{
		if (data->dire_pl == 'u')
			mlx_put_image_to_window(data->mlx_pt, data->win_pt,
				data->pla_up, x * 50, y * 50);
		else if (data->dire_pl == 'r')
			mlx_put_image_to_window(data->mlx_pt, data->win_pt,
				data->pla_ri, x * 50, y * 50);
		else if (data->dire_pl == 'l')
			mlx_put_image_to_window(data->mlx_pt, data->win_pt,
				data->pla_le, x * 50, y * 50);
		else
			mlx_put_image_to_window(data->mlx_pt, data->win_pt,
				data->pla_do, x * 50, y * 50);
	}
	else
		ft_check_if(x, y, data);
}

void	ft_fill_window(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_2[y])
	{
		x = 0;
		while (data->map_2[y][x])
		{
			ft_check_for_fill(x, y, data);
			x++;
		}
		y++;
	}
	data->itoa_n = ft_itoa(data->moves_c);
	if (!data->itoa_n)
		ft_handle_error(-1, "Error", data);
	mlx_string_put(data->mlx_pt, data->win_pt, 10, 12, 0xFFFFFF,
		data->itoa_n);
	free(data->itoa_n);
}
