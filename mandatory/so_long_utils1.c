/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:25 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 10:26:29 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_manage_so_long(t_data *data, char *file)
{
	ft_check_extention(file, data);
	ft_memset(data, 0, sizeof(data));
	data->map_1 = ft_read_map(file, data);
	data->map_2 = ft_read_map(file, data);
	ft_is_valid(data);
}

void	ft_check_position(int x, int y, t_data *data)
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

void	ft_check_fill_window(int x, int y, t_data *data)
{
	if (data->map_2[y][x] == '1')
		mlx_put_image_to_window(data->mlx_pt, data->win_pt,
			data->wall__, x * 50, y * 50);
	else if (data->map_2[y][x] == '0')
		mlx_put_image_to_window(data->mlx_pt, data->win_pt,
			data->floor_, x * 50, y * 50);
	else if (data->map_2[y][x] == 'P')
		ft_check_position(x, y, data);
	else if (data->map_2[y][x] == 'C')
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
			ft_check_fill_window(x, y, data);
			x++;
		}
		y++;
	}
}

char	**ft_read_map(char *file, t_data *data)
{
	char	**map;
	char	*buff;
	int		fd;
	int		n;

	n = 0;
	map = ft_alloc_map(data, file);
	fd = open(file, O_RDONLY);
	ft_handle_error(fd, "Error", data);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (buff[0] == '\0')
			ft_handle_error(-1, "Error", data);
		if (n == data->m_len_y - 1 && ft_strfind(buff) == 1)
			ft_handle_error(-1, "Error", data);
		map[n++] = ft_strtrim((const char *)buff, "\n");
		free(buff);
	}
	map[n] = 0;
	close(fd);
	return (map);
}
