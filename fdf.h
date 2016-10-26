/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:39:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 14:13:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define OX		100
# define OY		100
# define GAP_X			60
# define GAP_Y			60
# define S_Z			2

# include "get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "libmlx/mlx.h"

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

typedef struct		s_para
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}					t_para;

typedef struct		s_env2
{
	void			*mlx;
	void			*win;
	int				nb_lines;
	int				*col;
	t_coord			**coord;
	int				offx;
	int				offy;
	int				coeff;
	int				color;
	int				i;
	int				error;
}					t_env2;

void				ft_read_map(char *file, t_env2 *e);
int					get_next_line(int const fd, char **line);
int					key_hook(int keycode, t_env2 *env2);
int					expose_hook(t_env2 *env2);
t_coord				get_coord(t_env2 *e2, t_coord c1,
		t_coord (*f)(int, int, int));
t_coord				ft_iso(int x, int y, int z);
int					ft_print_line(t_env2 *env2, t_coord coord1, t_coord coord2);
void				draw(t_env2 *env2);
void				ft_getpoint(char *line, t_env2 *env2, int j);
void				ft_getpoint2(t_env2 *env2, int j, int k);
int					ft_get_col(char *line, t_env2 *env2, int i);
void				ft_read_map(char *file, t_env2 *env2);
void				ft_read_map2(char *file, t_env2 *env2, char *line);
void				ft_init(t_env2 *env2);
void				ft_init2(t_para *para1);
void				draw2(t_env2 *env2);
void				key_hook2(int keycode, t_env2 *env2);

#endif
