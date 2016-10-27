# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/03 00:07:39 by syusof            #+#    #+#              #
#    Updated: 2016/10/27 14:49:06 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = get_next_line.c ft_read_map1.c mlx.c ft_init.c ft_checkmode.c \
	   ft_draw1.c ft_getpoint11.c ft_getpoint12.c ft_functiond.c ft_getcol.c

OFILES = get_next_line.o ft_read_map1.o mlx.o ft_init.o ft_checkmode.o \
		 ft_draw1.o ft_getpoint11.o ft_getpoint12.o ft_functiond.o \
		 ft_getcol.o

FLAGS = -Wall -Werror -Wextra -I libft/includes/ -c

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
