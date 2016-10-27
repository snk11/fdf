/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:39:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/27 10:38:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define OX		400
# define OY		500
# define GAP_X			15
# define GAP_Y			15
# define S_Z			10

# include "get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "libmlx/mlx.h"
/*
typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;
*/
typedef struct		s_para
{
	int		dx;
	int		dy;
	int		cumul;
	int		x;
	int		y;
	int		i;
	int		xinc;
	int		yinc;
}					t_para;

typedef struct		s_ca
{
	int		i;
	int		start;
	int		k;
	int		tmp;
}
					t_ca;

typedef struct		s_doub
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_doub;

typedef struct		s_env2
{
	void			*mlx;
	void			*win;
	int				nb_lines;
	int				*col;
	t_doub			**doub1;
	int				offx;
	int				offy;
	int				coeff;
	int				color;
	int				i;
	int				error;
	int				readmode;
}					t_env2;

int					get_next_line(int const fd, char **line);
int					key_hook1(int keycode, t_env2 *env2);
void				key_hook3(int keycode, t_env2 *env2);
int					expose_hook1(t_env2 *env2);
int					ft_print_line1(t_env2 *env2, t_doub coord1, t_doub coord2);
void				draw1(t_env2 *env2);
void				draw11(t_env2 *env2);
void				ft_init(t_env2 *env2);
void				ft_init2(t_para *para1);
void				ft_init3(t_ca *c1);
int					ft_checkmode(char *line);
void				ft_read_map1(char *file, t_env2 *env2);
void				ft_read_map11(char *file, t_env2 *env2, char *line);
void				ft_getpoint1(char *line, t_env2 *env2, int j);
void				ft_getpoint3(t_env2 *env2, int j, int k);
void				ft_getpoint11(t_env2 *env2, char *line, int j, t_ca *c1);
void				ft_getpoint12(t_env2 *env2, char *line, int j, t_ca *c1);
int					ft_get_col1(char *line, t_env2 *env2, int i);
void				ft_print_line11(t_env2 *env2, t_para para1);
void				ft_print_line12(t_env2 *env2, t_para para1);
t_doub				get_coord1(t_env2 *e2, t_doub c1,
		t_doub (*f)(int, int, int));
t_doub				ft_iso1(int x, int y, int z);
int					ft_get_col1(char *line, t_env2 *env2, int i);

#endif
