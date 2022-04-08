/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:38:46 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/08 02:05:38 by yamzil           ###   ########.fr       */
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

# define WIN_HEIGHT 1280
# define WIN_WIDTH 720

typedef struct s_game {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
	int		player;
	int		exit;
	int		collectibles;
}	t_g;

// libft Functions
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

// Get Next Line
char	*get_next_line(int fd);

// Map Checker
int		ft_checkarg(int ac, char **av);
int		ft_getlencolumns(char **av);
int		ft_getlenrow(t_g map);
t_g		ft_getmap(t_g map, char **av);
void	ft_checksurrounded(char **av, t_g map);
void	ft_checklen(t_g map);

// Map's ELements
int		ft_checkplayer(t_g map, t_g player);
int		ft_checkexit(t_g map, t_g exit);
int		ft_checkcollectibles(t_g map, t_g collectibles);
void	ft_checkelemnts(char **av, t_g map);
void	ft_contents(t_g map, t_g player, t_g exit, t_g collectibles);

#endif