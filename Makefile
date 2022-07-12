# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 12:30:05 by igondra-          #+#    #+#              #
#    Updated: 2022/07/12 12:30:43 by igondra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
 
OBJS = $(SRCS:.c=.o)

SRCS = ft_printf.c\
	   ft_printf_func.c

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc -Wall -Wextra -Werror -c $(SRCS) 

clean: 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re