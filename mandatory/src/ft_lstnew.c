/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:43:56 by momari            #+#    #+#             */
/*   Updated: 2024/02/04 22:33:56 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// t_datamap	ft_lstnew_data()
// {
// 	t_datamap	newnode;

// 	newnode.len = 0;
// 	newnode.n_collectible = 0;
// 	newnode.n_empty_space = 0;
// 	newnode.n_map_exit = 0;
// 	newnode.n_players = 0;
// 	newnode.n_wall = 0;
// 	return (newnode);
// }

// t_variables	ft_lstnew_variables(char *str, t_datamap *data)
// {
// 	t_variables	newnode;

//     newnode.map = ft_validatemap(str, data);
//     newnode.mlx = mlx_init();
//     newnode.mlx_window = mlx_new_window(newnode.mlx, 27 * 50, 6 * 50, "momari");
//     newnode.floor = mlx_xpm_file_to_image(newnode.mlx, "mandatory/images/newimg.xpm", &newnode.a, &newnode.b);
//     newnode.player = mlx_xpm_file_to_image(newnode.mlx, "mandatory/images/player.xpm", &newnode.a, &newnode.b);
//     newnode.wall = mlx_xpm_file_to_image(newnode.mlx, "mandatory/images/wall.xpm", &newnode.a, &newnode.b);
// 	return (newnode);
// }

t_map	ft_lstnew(char *content)
{
	t_map	newnode;

	newnode.content = ft_strdup(content);
	newnode.next = NULL;
	return (newnode);
}
t_player_position ft_lstnew_playerpos()
{
	t_player_position newnode;

	newnode.x = -1;
	newnode.y = -1;
	return (newnode);
}