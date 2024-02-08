/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:14:17 by momari            #+#    #+#             */
/*   Updated: 2024/02/08 11:51:11 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(int ac, char **av)
{
    t_variables variables;

    if (ac != 2)
        return (1);
    ft_memset(&variables, 0, sizeof(t_variables));
    ft_parsing_map(av[1], &variables);
    ft_fill_window(&variables);
    mlx_loop(variables.mlx);
    return (0);
}

