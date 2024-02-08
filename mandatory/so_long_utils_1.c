/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:37:11 by momari            #+#    #+#             */
/*   Updated: 2024/02/05 18:02:01 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_checkline(char *str, t_datamap *data, t_variables *vars, char c)
{
    int i;

    i = 0;
    if (str[i] != '1')
        ft_putendl_fd("Error1", 2);
    while (str[i + 1])
    {
        if (c == '1')
        {
            if (str[i] != '1')
                ft_putendl_fd("Error", 2);
        }
        else
            ft_handle_char(vars, data, str[i], i);
        i++;
    }
    if (str[i++] != '1')
        ft_putendl_fd("Error4", 2);
    return (i);
}

void ft_check_lines(char **map, t_datamap *data, t_variables *vars)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(map[i]);
    data->x = len;
    ft_checkline(map[i], data, vars, '1');
    i++;
    while (map[i + 1])
    {
        data->len = ft_checkline(map[i], data, vars, '2');
        if (data->pos_py == -1)
        {
            data->pos_py = i;
            vars->pos_py = i;
        }
        if (data->len != len)
            ft_putendl_fd("Error", 2);
        i++;
    }
    data->len = ft_checkline(map[i], data, vars, '1');
    if (data->len != len)
        ft_putendl_fd("Error", 2);
    if (data->n_players != 1 || data->n_collectible < 1 || data->n_map_exit != 1)
        ft_putendl_fd("Error", 2);
}

void    ft_validatemap(char *str, t_datamap   *data, t_variables *var)
{
    char *line;
    int fd;
    int i;

    i = 0;
    data->y = ft_count_lines(str);
    fd = open(str, O_RDONLY);
    ft_handle_error(fd);
    var->map = (char **)malloc((data->y + 1) * sizeof(char *));
    if (!var->map)
        ft_handle_error(-1);
    var->map_for_validate = (char **)malloc((data->y + 1) * sizeof(char *));
    if (!var->map_for_validate)
        ft_handle_error(-1);
    line = get_next_line(fd);
    while (line)
    {
        ft_lstadd_back(var->map, line, i);
        ft_lstadd_back(var->map_for_validate, line, i);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    var->map[i] = 0;
    var->map_for_validate[i] = 0;
    ft_check_lines(var->map, data, var);
}

int ft_count_lines(char *str)
{
    char *line;
    int fd;
    int n;

    n = 0;
    fd = open(str, O_RDONLY);
    ft_handle_error(fd);
    line = get_next_line(fd);
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        n++;
    }
    if (line)
        free(line);
    close(fd);
    return (n);
}
void    flood_fill(t_variables *var, int x, int y, t_datamap *datamap)
{
    if (x < 0 || x > 28 || y < 0 || y > 6)
        return;
    if (var->map[y][x] == '1')
        return ;
    if (var->map[y][x] == 'P')
    {
        var->map[y][x] = '1';
        datamap->n_players--;
    }
    else if (var->map[y][x] == 'C')
    {
        var->map[y][x] = '1';
        datamap->n_collectible--;
    }
    else if (var->map[y][x] == 'E')
    {
        var->map[y][x] = '1';
        datamap->n_map_exit--;
        // return;
    }
    else if (var->map[y][x] == '0')
    {
        var->map[y][x] = '1';
        datamap->n_empty_space--;
    }
    flood_fill(var, x, y - 1, datamap);
    flood_fill(var, x, y + 1, datamap);
    flood_fill(var, x + 1, y, datamap);
    flood_fill(var, x - 1, y, datamap);
}
