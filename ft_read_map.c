/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 00:03:17 by syusof            #+#    #+#             */
/*   Updated: 2015/05/29 14:23:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"


static void		ft_getpoint(char *line, t_env2 ***env2, int j)
{
	int		i;
	int		start;
	int		k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) && line[i] != '+' && line[i] != '-')
		{
			start = i;
			while (line[i] && ft_isdigit(line[i]) && line[i] != '+' && line[i] != '-')
				i++;
			((**env2)->coord)[j][k].x = k;
			((**env2)->coord)[j][k].y = j;
			((**env2)->coord)[j][k].z = ft_atoi(ft_strsub(line, start, i - start));
			k++;
		}
		else
			i++;
	}
}

static	int	ft_get_col(char *line, t_env2 ***env2, int i)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (line[k])
	{
		if (ft_isdigit(line[k]) && line[k] != '+' && line[k] != '-')
		{
			while (line[k] && ft_isdigit(line[k]) && line[k] != '+' && line[k] != '-')
				k++;
			n++;
		}
		else
		{
//			while (line[k] == ' ')
				k++;
		}
	}
	((**env2)->col)[i] = n;
	return (n);
}


void	ft_read_map(char *file, t_env2 **env2)
{
	int		fd;
	char	*line;
	int	i;
	int	j;
	int		c;
	
	c = 0;
	line = NULL;
	if(!j)
		j = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		j++;
		(*env2)->nb_lines = j;
	}
	close(fd);
	(*env2)->coord = (t_coord**)malloc(sizeof(t_coord*) * j);
	fd = open(file, O_RDONLY);
	(*env2)->col = (int*)malloc(sizeof(int) * j);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		c = ft_get_col(line,&env2,i);
		((*env2)->coord)[i] = (t_coord*)malloc(sizeof(t_coord) * c);
		i++;
	}
	close(fd);
	j = 0;
	fd = open(file, O_RDONLY);
		while (get_next_line(fd, &line) > 0)
	{
		ft_getpoint(line,&env2, j);
		j++;
	}
	close(fd);
}


