# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/03 00:07:39 by syusof            #+#    #+#              #
#    Updated: 2016/10/26 13:12:31 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = get_next_line.c ft_read_map.c ft_read_map2.c mlx.c mlx2.c ft_init.c

OFILES = $(SRCS:.c=.o)

FLAGS = -I libft/includes/ -c

MAIN = fdf.c

OMAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ re
	make -C libmlx
	gcc $(FLAGS) $(SRCS)
	gcc $(FLAGS) $(MAIN)
	gcc -o $(NAME) $(OFILES) $(OMAIN) -L libft/ -lft -L libmlx/ -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OFILES)
	rm -f $(OMAIN)
	make -C libft/ clean
	make -C libmlx/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
