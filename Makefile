# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atastet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 10:37:46 by atastet           #+#    #+#              #
#    Updated: 2018/05/15 18:53:40 by atastet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	gnl

SRC_PATH	=	

SRC		=	main.c \
			get_next_line.c

SRC_POS		= 	$(addprefix $(SRC_PATH),$(SRC))

OBJS 		= 	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I libft/

all :		$(NAME)

$(NAME) :	$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L libft -lft

$(OBJS) :	get_next_line.h
	$(CC) $(CFLAGS) -c $(SRC_POS)

%.o		: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean : 
	rm -f $(OBJS)
	make clean -C ./libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft/

re : fclean all

.PHONY : all re clean fclean
