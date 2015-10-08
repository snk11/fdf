/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:39:59 by syusof            #+#    #+#             */
/*   Updated: 2015/05/29 11:56:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define OX		100
# define OY		100
# define GAP_X			20
# define GAP_Y			20
# define S_Z			5


# include "get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <math.h>
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
}					t_env2;

void		ft_read_map(char *file, t_env2 **e);
int		get_next_line(int const fd, char **line);
int		key_hook(int keycode, t_env2 *env2);
int		expose_hook(t_env2 *env2);


# endif
