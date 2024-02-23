/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:10:54 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 11:21:28 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_handle_error(-1, "Error", &data);
	ft_manage_so_long(&data, av[1]);
	mlx_loop(data.mlx_pt);
}
