# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 15:15:26 by hbruvry           #+#    #+#              #
#    Updated: 2017/12/09 17:53:35 by hbruvry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #KE) -C subdir

NAME =		fillit

HEAD =		fillit.h

LIBFT =		LIBFT

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft
		gcc -o $(NAME) $(LIBFT)/libft.a fillit.c

libft:
	make -C $(LIBFT)

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY : libft clean fclean all re
