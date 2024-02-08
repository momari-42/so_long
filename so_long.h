/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:15:49 by momari            #+#    #+#             */
/*   Updated: 2024/02/08 11:35:18 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_map
{
	char			*content;
	struct s_map	*next;
}	t_map;


typedef struct s_datamap
{
	int	n_empty_space;
	int n_collectible;
	int n_map_exit;
	int n_players;
	int n_wall;
	int pos_px;
	int pos_py;
	int len;
	int x;
	int	y;
}	t_datamap;

typedef struct s_variable
{
    char    **map_for_validate;
	void    *mlx_window;
    void    *player_posa;
    void    *player_posb;
    void    *floor;
    void    *wall;
    char    **map;
    void    *mlx;
	float pos_px;
	float pos_py;
    int 	a;
    int 	b;
} t_variables;

typedef struct s_player_position
{
	int x;
	int y;
} t_player_position;

int		ft_search(char *str);
char	*ft_newbuffer(char *src);
char	*ft_createstr(char *src, char **string);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dst, char const *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_allocate(char **src);
int		ft_check(int fd);
void	*ft_memset(void *b, int c, size_t len);
void	ft_validatemap(char *str, t_datamap   *data, t_variables *var);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);


void	ft_lstadd_back(char **map, char *line, int i);
// void	ft_lstadd_back_data(t_datamap **lst, t_datamap *new);
void	ft_lstclear(t_map **lst, void (*del)(void *));
t_map	*ft_lstlast(t_map *lst);
// t_map	ft_lstnew(char *content);
t_datamap	ft_lstnew_data();
// int	ft_lstsize(t_map lst);
char	*ft_strdup(const char *s1);
int ft_count_lines(char *str);
void    flood_fill(t_variables *var, int x, int y, t_datamap *datamap);
// t_variables	ft_lstnew_variables(char *str, t_datamap *data);
void ft_handle_error(int n);
void ft_parsing_map(char *str, t_variables *var);
void ft_handle_char(t_variables *var, t_datamap *data, char c, int n);
void ft_fill_window(t_variables *variables);
#endif