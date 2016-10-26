/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:39:59 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 12:42:11 by syusof           ###   ########.fr       */
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
void		ft_getpoint(char *line, t_env2 *env2, int j);
void		ft_getpoint2(t_env2 *env2, int j, int k);
int		ft_get_col(char *line, t_env2 *env2, int i);
void			ft_read_map(char *file, t_env2 *env2);
void		ft_read_map2(char *file,t_env2 *env2,char *line);
void	ft_init(t_env2 *env2);

#endif
