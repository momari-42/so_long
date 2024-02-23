/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:10:48 by momari            #+#    #+#             */
/*   Updated: 2024/02/22 11:16:09 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_data
{
	int		a;
	int		b;
	void	*mlx_pt;
	void	*win_pt;
	void	*pla_up;
	void	*pla_do;
	void	*pla_le;
	void	*pla_ri;
	void	*floor_;
	void	*wall__;
	void	*collec;
	void	*door_o;
	void	*door_c;
	char	**map_1;
	char	**map_2;
	int		m_len_x;
	int		m_len_y;
	int		p_pla_x;
	int		p_pla_y;
	int		n_playe;
	int		n_colle;
	int		n_coll2;
	int		n_exitm;
	int		check_d;
	int		moves_c;
	char	dire_pl;
}	t_data;

void	ft_manage_so_long(t_data *data, char *file);
void	ft_check_extention(char *file, t_data *data);
void	ft_fill_window(t_data *data);
char	**ft_read_map(char *file, t_data *data);
int		ft_strfind(char *str);
char	**ft_alloc_map(t_data *data, char *file);
void	ft_is_valid(t_data *data);
void	ft_run_window(t_data *data);
int		exit_func(t_data *data);
int		move(int keycode, t_data *data);
void	animate_le(t_data *data);
void	animate_ri(t_data *data);
void	animate_do(t_data *data);
void	animate_up(t_data *data);
void	ft_manage_flood(t_data *data);
void	ft_flood_fill(t_data *data, int y, int x);
void	ft_check_fl(t_data *data);
void	ft_check_all(t_data *data);
void	ft_check_char(t_data *data, char c, int i);
void	ft_handle_error(int n, char *message, t_data *data);
void	ft_destroy_images(t_data *data);
void	ft_freestrings(t_data *data);
void	ft_check_position(int x, int y, t_data *data);

#endif
