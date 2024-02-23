/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils6_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:15:02 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 07:50:15 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_func(t_data *data)
{
	ft_handle_error(-2, "Closed button pressed", data);
	return (0);
}

void	ft_handle_error(int n, char *message, t_data *data)
{
	if (n == -1)
	{
		ft_putendl_fd(message, 2);
		exit(1);
	}
	else if (n == -2)
	{
		ft_freestrings(data);
		ft_destroy_images(data);
		ft_putendl_fd(message, 1);
		exit(0);
	}
	else if (n == -4)
	{
		ft_freestrings(data);
		ft_putendl_fd(message, 1);
		exit(1);
	}
}

void	ft_destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx_pt, data->pla_up);
	mlx_destroy_image(data->mlx_pt, data->pla_do);
	mlx_destroy_image(data->mlx_pt, data->pla_le);
	mlx_destroy_image(data->mlx_pt, data->pla_ri);
	mlx_destroy_image(data->mlx_pt, data->floor_);
	mlx_destroy_image(data->mlx_pt, data->wall__);
	mlx_destroy_image(data->mlx_pt, data->collec);
	mlx_destroy_image(data->mlx_pt, data->door_o);
	mlx_destroy_image(data->mlx_pt, data->door_c);
	mlx_destroy_image(data->mlx_pt, data->enemy[0]);
	mlx_destroy_image(data->mlx_pt, data->enemy[1]);
	mlx_destroy_image(data->mlx_pt, data->enemy[2]);
	mlx_destroy_image(data->mlx_pt, data->enemy[3]);
	mlx_destroy_image(data->mlx_pt, data->enemy[4]);
	mlx_destroy_image(data->mlx_pt, data->enemy[5]);
	free(data->enemy);
	mlx_destroy_window(data->mlx_pt, data->win_pt);
}

void	ft_freestrings(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_1[i])
		free(data->map_1[i++]);
	if (data->map_1)
		free(data->map_1);
	i = 0;
	while (data->map_2[i])
		free(data->map_2[i++]);
	if (data->map_2)
		free(data->map_2);
}

void	ft_is_valid(t_data *data)
{
	ft_check_fl(data);
	ft_check_all(data);
	ft_manage_flood(data);
	if ((data->m_len_x * 50) > (49 * 50)
		|| (data->m_len_y * 50) > (26 * 50))
		ft_handle_error(-4, "Error", data);
	ft_run_window(data);
}
