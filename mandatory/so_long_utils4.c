/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:50:55 by momari            #+#    #+#             */
/*   Updated: 2024/02/21 12:58:02 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_manage_flood(t_data *data)
{
	ft_flood_fill(data, data->p_pla_y, data->p_pla_x);
	if (data->n_playe != 0 || data->n_exitm != 0 || data->n_colle != 0)
		ft_handle_error(-4, "Error", data);
}

void	ft_flood_fill(t_data *data, int y, int x)
{
	if (data->map_1[y][x] == '1')
		return ;
	if (data->map_1[y][x] == 'P')
	{
		data->map_1[y][x] = '1';
		data->n_playe--;
	}
	else if (data->map_1[y][x] == 'C')
	{
		data->map_1[y][x] = '1';
		data->n_colle--;
	}
	else if (data->map_1[y][x] == 'E')
	{
		data->map_1[y][x] = '1';
		data->n_exitm--;
		return ;
	}
	else if (data->map_1[y][x] == '0')
		data->map_1[y][x] = '1';
	ft_flood_fill(data, y - 1, x);
	ft_flood_fill(data, y + 1, x);
	ft_flood_fill(data, y, x + 1);
	ft_flood_fill(data, y, x - 1);
}

void	ft_check_fl(t_data *data)
{
	int	n;

	n = 0;
	while (data->map_1[0][n] && data->map_1[0][n] == '1')
		n++;
	if (data->map_1[0][n])
		ft_handle_error(-4, "Error", data);
	data->m_len_x = n;
	n = 0;
	while (data->map_1[0][n] && data->map_1[data->m_len_y - 1][n] == '1')
		n++;
	if (data->map_1[data->m_len_y - 1][n] || n != data->m_len_x)
		ft_handle_error(-4, "Error", data);
}

void	ft_check_all(t_data *data)
{
	int	i;
	int	n;

	n = 1;
	while (data->map_1[n])
	{
		if (data->map_1[n][0] != '1')
			ft_handle_error(-4, "Error", data);
		i = 1;
		while (data->map_1[n][i + 1])
		{
			ft_check_char(data, data->map_1[n][i], i);
			i++;
		}
		if (data->map_1[n][i++] != '1')
			ft_handle_error(-4, "Error", data);
		if (data->m_len_x != i)
			ft_handle_error(-4, "Error", data);
		if (data->p_pla_y == -1)
			data->p_pla_y = n;
		n++;
	}
	data->n_coll2 = data->n_colle;
	if (data->n_colle < 1 || data->n_exitm != 1 || data->n_playe != 1)
		ft_handle_error(-4, "Error", data);
}

void	ft_check_char(t_data *data, char c, int i)
{
	if (c == '1')
		;
	else if (c == '0')
		;
	else if (c == 'P')
	{
		data->n_playe++;
		data->p_pla_x = i;
		data->p_pla_y = -1;
	}
	else if (c == 'C')
		data->n_colle++;
	else if (c == 'E')
		data->n_exitm++;
	else
		ft_handle_error(-4, "Error", data);
}
