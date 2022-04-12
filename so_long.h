/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:38:46 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/12 02:08:49 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

enum {
	key_w = 13,
	key_s = 1,
	key_a = 0,
	key_d = 2,
	key_ecs = 53,
	key_cross = 17,	
};

typedef struct s_game {
	int		wall_width;
	int		wall_height;
	int		grasse_width;
	int		grasse_height;
	int		hero_width;
	int		hero_height;
	int		lettuce_width;
	int		lettuce_height;
	int		door_width;
	int		door_height;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*grasse;
	void	*hero;
	void	*lettuce;
	void	*door;
	char	**map;
	int		player;
	int		exit;
	int		collectibles;
	int		height;
	int		width;
	int		j_place;
	int		i_place;
}	t_g;

// libft Functions
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);

// Get Next Line
char	*get_next_line(int fd);

// Map Checker
void	ft_checksurrounded(char **av, t_g *map);
void	ft_checklen(t_g *map);
int		ft_checkarg(int ac, char **av);
void	ft_getmap(t_g *map, char **av);

// Map's ELements
void	ft_contents(t_g map);
void	ft_checkcollectibles(t_g *map);
void	ft_checkelemnts(t_g *map);
void	ft_checkplayer(t_g *map);
void	ft_checkexit(t_g *map);

//Coune line
void	ft_getlencolumns(char **av, t_g *map);
int		ft_getlast(t_g *map);
void	ft_getlenrow(t_g *map);

//THE GAME
void	ft_solong(t_g *map);
void	ft_putimg(t_g *map);

//Key Hook
int 	ft_mouvment(int key_code, t_g *map);
void	ft_check(int key_code, t_g *map, int i, int j);
#endif