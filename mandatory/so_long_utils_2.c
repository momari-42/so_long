/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:09:33 by momari            #+#    #+#             */
/*   Updated: 2024/02/08 22:27:42 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void redraw_scene(t_variables *vars, int n) {
    vars->map_for_validate[(int)vars->pos_py + 1][(int)vars->pos_px] = '0';
    ft_fill_window(vars);
    if (n % 2 == 1)
        mlx_put_image_to_window(vars->mlx, vars->mlx_window, vars->player_posa, vars->pos_px * 50, vars->pos_py * 50);
    else
        mlx_put_image_to_window(vars->mlx, vars->mlx_window, vars->player_posb, vars->pos_px * 50, vars->pos_py * 50);
}


void animate_frame(int keycode, t_variables *vars) {
    (void)keycode;
    static int n = 0;
    int frames = 5;
    static int current_frame = 0;
    double delta_y = -1.0 / frames;

    if (current_frame < frames) {
        vars->pos_py += delta_y;
        redraw_scene(vars, n);
        current_frame++;
        n++;
    }
    else
        current_frame = 0;
}

void animate_framey(int keycode, t_variables *vars) {
    (void)keycode;
    static int n = 0;
    int frames = 5;
    static int current_frame = 0;
    double delta_y = 1.0 / frames;

    if (current_frame < frames) {
        vars->pos_py += delta_y;
        redraw_scene(vars, n);
        current_frame++;
        n++;
    }
    else
        current_frame = 0;
}

void animate_framexl(int keycode, t_variables *vars) {
    (void)keycode;
    static int n = 0;
    int frames = 10;
    static int current_frame = 0;
    double delta_y = -1.0 / frames;

    if (current_frame < frames) {
        vars->pos_px += delta_y;
        redraw_scene(vars, n);
        current_frame++;
        n++;
    }
    else
        current_frame = 0;
}

void animate_framexr(int keycode, t_variables *vars) {
    (void)keycode;
    static int n = 0;
    int frames = 10;
    static int current_frame = 0;
    double delta_y = 1.0 / frames;

    if (current_frame < frames) {
        vars->pos_px += delta_y;
        redraw_scene(vars, n);
        current_frame++;
        n++;
    }
    else
        current_frame = 0;
}

int move(int keycode, t_variables *vars) {
    // printf("%d    %d", data.pos_py, data.pos_px);
    if (keycode == 126)
        animate_frame(keycode, vars);
    else if (keycode == 125)
        animate_framey(keycode, vars);
    else if (keycode == 124)
        animate_framexr(keycode, vars);
    else if (keycode == 123)
        animate_framexl(keycode, vars);
    return (0);
}

void ft_parsing_map(char *str, t_variables *var)
{
    t_datamap data;

    ft_memset(&data, 0, sizeof(t_datamap));
    ft_validatemap(str, &data, var);
    flood_fill(var, data.pos_px, data.pos_py, &data);
    if (data.n_map_exit != 0 || data.n_collectible != 0)
        ft_putendl_fd("Error", 2);
    var->mlx = mlx_init();
    var->mlx_window = mlx_new_window(var->mlx, data.x * 50, data.y * 50, "momari");
    mlx_hook(var->mlx_window, 2, 1L<<0, move, var);
    var->floor = mlx_xpm_file_to_image(var->mlx, "mandatory/images/floor.xpm", &var->a, &var->b);
    var->player_posa = mlx_xpm_file_to_image(var->mlx, "mandatory/images/player_posa.xpm", &var->a, &var->b);
    var->player_posb = mlx_xpm_file_to_image(var->mlx, "mandatory/images/player_posb.xpm", &var->a, &var->b);
    var->wall = mlx_xpm_file_to_image(var->mlx, "mandatory/images/wall.xpm", &var->a, &var->b);
}
void ft_handle_error(int n)
{
    if (n < 0)
        ft_putendl_fd("Error", 2);
}

void ft_handle_char(t_variables *var, t_datamap *data, char c, int n)
{
    if (c == '0')
        data->n_empty_space++;
    else if (c == '1')
        data->n_wall++;
    else if (c == 'C')
        data->n_collectible++;
    else if (c == 'E')
        data->n_map_exit++;
    else if (c == 'P')
    {
        data->n_players++;
        data->pos_px = n;
        data->pos_py = -1;
        var->pos_px = n;
        var->pos_py = -1;
    }
    else
        ft_putendl_fd("Error3", 2);
}

// int key_hook(int keycode, t_variables *vars)
// {
//     (void)key_hook;
//     (void)vars;
//     printf("hello from hook !!!");
//     return (0);
// }

void ft_fill_window(t_variables *variables)
{
    int i;

    i = 0;
    mlx_clear_window(variables->mlx, variables->mlx_window);
    while (variables->map_for_validate[i])
    {
        int j = 0;
        while (variables->map_for_validate[i][j])
        {
            if (variables->map_for_validate[i][j] == '1')
                mlx_put_image_to_window(variables->mlx, variables->mlx_window, variables->wall, j * 50, i * 50);
            else if (variables->map_for_validate[i][j] == '0')
                mlx_put_image_to_window(variables->mlx, variables->mlx_window, variables->floor, j * 50, i * 50);
            else if (variables->map_for_validate[i][j] == 'P')
                mlx_put_image_to_window(variables->mlx, variables->mlx_window, variables->player_posa, j * 50, i * 50);
            else
                mlx_put_image_to_window(variables->mlx, variables->mlx_window, variables->floor, j * 50, i * 50);
            j++;
        }
        i++;
    }
}
