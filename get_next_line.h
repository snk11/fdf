/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 18:16:03 by syusof            #+#    #+#             */
/*   Updated: 2016/05/11 16:36:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# include "stdio.h"

# define BUFF_SIZE 8192

typedef struct		s_env
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	int		index;
}					t_env;

int					get_next_line(int const fd, char **line);

#endif
