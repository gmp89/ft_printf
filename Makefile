#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 15:39:10 by gpetrov           #+#    #+#              #
#    Updated: 2013/12/21 22:12:19 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=  libftprintf.a
SRCS	= ft_printf.c\
		ft_atoi.c\
		ft_putstr.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_strcpy.c\
		ft_putnbr.c\
		ft_strlen.c\
		ft_isdigit.c\
		ft_strdup.c
OBJS	= ${SRCS:.c=.o}
INC		= ./
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o: %.c
		cc -c $< -o $@ $(FLAGS) -I$(INC)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
