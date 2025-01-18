# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 10:59:50 by iabasala          #+#    #+#              #
#    Updated: 2024/11/14 18:16:12 by iabasala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS= -Wall -Wextra -Werror

SRCS =	ft_printf.c	ft_printhex_lower.c		ft_printhex_upper.c	ft_putnbr.c	ft_putstr.c	ft_printaddress.c	ft_putchar.c	ft_putnbr_unsigned.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
