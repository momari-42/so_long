/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:13:54 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 15:21:48 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	ft_strfind(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_alloc_map(t_data *data, char *file)
{
	char	**map;
	char	*buff;
	int		n_lin;
	int		fd;

	n_lin = 0;
	fd = open(file, O_RDONLY);
	ft_handle_error(fd, "Error", data);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		free(buff);
		n_lin++;
	}
	close(fd);
	if (n_lin == 0)
		ft_handle_error(-1, "Error", data);
	map = (char **)malloc((n_lin + 1) * sizeof(char *));
	if (!map)
		ft_handle_error(-1, "Error", data);
	data->m_len_y = n_lin;
	close(fd);
	return (map);
}

static void	ft_check_run(t_data *data)
{
	data->floor_ = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/floor.xpm", &(data->a), &(data->b));
	data->pla_up = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/player_u.xpm", &data->a, &data->b);
	data->pla_do = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/player_d.xpm", &data->a, &data->b);
	data->pla_le = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/player_l.xpm", &data->a, &data->b);
	data->pla_ri = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/player_r.xpm", &data->a, &data->b);
	data->wall__ = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/wall.xpm", &data->a, &data->b);
	data->collec = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/coll.xpm", &data->a, &data->b);
	data->door_c = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/door_c.xpm", &data->a, &data->b);
	data->door_o = mlx_xpm_file_to_image(data->mlx_pt,
			"bonus/textures/door_o.xpm", &data->a, &data->b);
	data->enemy = ft_init_enemy(data);
	if (!data->floor_ || !data->pla_up || !data->pla_do
		|| !data->pla_le || !data->pla_ri || !data->wall__
		|| !data->collec || !data->door_c || !data->door_o || !data->enemy)
		ft_handle_error(-4, "Error", data);
}

void	ft_run_window(t_data *data)
{
	data->mlx_pt = mlx_init();
	if (!data->mlx_pt)
		ft_handle_error(-4, "Error", data);
	data->win_pt = mlx_new_window(data->mlx_pt, data->m_len_x * 50,
			data->m_len_y * 50, "momari");
	if (!data->win_pt)
		ft_handle_error(-4, "Error", data);
	ft_check_run(data);
	ft_fill_window(data);
	mlx_loop_hook(data->mlx_pt, animate_enemy, data);
	mlx_hook(data->win_pt, 2, 1L << 0, move, data);
	mlx_hook(data->win_pt, 17, 0, exit_func, data);
}
