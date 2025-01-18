# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 11:23:52 by iabasala          #+#    #+#              #
#    Updated: 2025/01/18 16:22:11 by iabasala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
SNAME = server
SRCS = server.c
SRCC = client.c
SRCP = ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)

all: $(CNAME) $(SNAME)

$(SNAME) : $(OBJS)
		cc $(CFLAGS) -o $(SNAME) $(OBJS)  $(SRCP)

$(CNAME) : $(OBJC)
		cc $(CFLAGS) -o $(CNAME) $(OBJC) $(SRCP)

clean:
	rm -f $(OBJS) $(OBJC)
fclean: clean
	rm -f $(CNAME) $(SNAME)
re: fclean all