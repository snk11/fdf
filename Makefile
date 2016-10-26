# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/03 00:07:39 by syusof            #+#    #+#              #
#    Updated: 2016/10/26 17:11:33 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = get_next_line.c ft_read_map0.c ft_read_map1.c ft_read_map2.c mlx.c \
mlx2.c ft_init.c ft_checkmode.c ft_draw1.c ft_draw2.c

OFILES = get_next_line.o ft_read_map0.o ft_read_map1.o ft_read_map2.o mlx.o \
mlx2.o ft_init.o ft_checkmode.o ft_draw1.o ft_draw2.o

FLAGS = -I libft/includes/ -c

MAIN = fdf.c

OMAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ re
	make -C libmlx
	gcc $(FLAGS) $(MAIN) $(SRCS)
	gcc -o $(NAME) $(OFILES) $(OMAIN) -L libft/ -lft -L libmlx/ -lmlx \
		-framework OpenGL -framework AppKit

clean:
	rm -f $(OFILES)
	rm -f $(OMAIN)
	make -C libft/ clean
	make -C libmlx/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
