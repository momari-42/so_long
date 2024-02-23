/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:31 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 08:00:50 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx_pt, data->win_pt);
	if (keycode == 53)
		ft_handle_error(-2, "ESC button pressed", data);
	if (keycode == 126 || keycode == 13)
		animate_up(data);
	else if (keycode == 125 || keycode == 1)
		animate_do(data);
	else if (keycode == 124 || keycode == 2)
		animate_ri(data);
	else if (keycode == 123 || keycode == 0)
		animate_le(data);
	ft_fill_window(data);
	return (0);
}

void	animate_up(t_data *data)
{
	if (data->map_2[data->p_pla_y - 1][data->p_pla_x] != '1')
	{
		if (data->map_2[data->p_pla_y - 1][data->p_pla_x] == 'E')
		{
			if (data->n_coll2 == 0)
			{
				ft_printf("You move %d times\n", ++data->moves_c);
				ft_handle_error(-2, "You win ;)", data);
			}
			return ;
		}
		else if (data->map_2[data->p_pla_y - 1][data->p_pla_x] == 'C')
		{
			data->n_coll2--;
			if (data->n_coll2 == 0)
				data->check_d = -1;
		}
		data->map_2[data->p_pla_y][data->p_pla_x] = '0';
		data->p_pla_y--;
		data->map_2[data->p_pla_y][data->p_pla_x] = 'P';
		data->moves_c++;
		ft_printf("You move %d times\n", data->moves_c);
	}
	data->dire_pl = 'u';
}

void	animate_do(t_data *data)
{
	if (data->map_2[data->p_pla_y + 1][data->p_pla_x] != '1')
	{
		if (data->map_2[data->p_pla_y + 1][data->p_pla_x] == 'E')
		{
			if (data->n_coll2 == 0)
			{
				ft_printf("You move %d times\n", ++data->moves_c);
				ft_handle_error(-2, "You win ;)", data);
			}
			return ;
		}
		else if (data->map_2[data->p_pla_y + 1][data->p_pla_x] == 'C')
		{
			data->n_coll2--;
			if (data->n_coll2 == 0)
				data->check_d = -1;
		}
		data->map_2[data->p_pla_y][data->p_pla_x] = '0';
		data->p_pla_y++;
		data->map_2[data->p_pla_y][data->p_pla_x] = 'P';
		data->moves_c++;
		ft_printf("You move %d times\n", data->moves_c);
	}
	data->dire_pl = 'd';
}

void	animate_ri(t_data *data)
{
	if (data->map_2[data->p_pla_y][data->p_pla_x + 1] != '1')
	{
		if (data->map_2[data->p_pla_y][data->p_pla_x + 1] == 'E')
		{
			if (data->n_coll2 == 0)
			{
				ft_printf("You move %d times\n", ++data->moves_c);
				ft_handle_error(-2, "You win ;)", data);
			}
			return ;
		}
		else if (data->map_2[data->p_pla_y][data->p_pla_x + 1] == 'C')
		{
			data->n_coll2--;
			if (data->n_coll2 == 0)
				data->check_d = -1;
		}
		data->map_2[data->p_pla_y][data->p_pla_x] = '0';
		data->p_pla_x++;
		data->map_2[data->p_pla_y][data->p_pla_x] = 'P';
		data->moves_c++;
		ft_printf("You move %d times\n", data->moves_c);
	}
	data->dire_pl = 'r';
}

void	animate_le(t_data *data)
{
	if (data->map_2[data->p_pla_y][data->p_pla_x - 1] != '1')
	{
		if (data->map_2[data->p_pla_y][data->p_pla_x - 1] == 'E')
		{
			if (data->n_coll2 == 0)
			{
				ft_printf("You move %d times\n", ++data->moves_c);
				ft_handle_error(-2, "You win ;)", data);
			}
			return ;
		}
		else if (data->map_2[data->p_pla_y][data->p_pla_x - 1] == 'C')
		{
			data->n_coll2--;
			if (data->n_coll2 == 0)
				data->check_d = -1;
		}
		data->map_2[data->p_pla_y][data->p_pla_x] = '0';
		data->p_pla_x--;
		data->map_2[data->p_pla_y][data->p_pla_x] = 'P';
		data->moves_c++;
		ft_printf("You move %d times\n", data->moves_c);
	}
	data->dire_pl = 'l';
}
