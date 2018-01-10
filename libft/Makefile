# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bteissei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/29 05:46:29 by bteissei          #+#    #+#              #
#    Updated: 2018/01/07 07:33:04 by bteissei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = annexfct.c \
	  annexfct2.c \
	  annexfct3.c \
	  annexfctall.c \
	  annexfctall2.c \
	  annexfctd.c \
	  annexfcto.c \
	  annexfctu.c \
	  annexfctx.c \
	  ft_itoa.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_printf.c \
	  ft_utoa.c \
	  parseall.c \
	  parsec.c \
	  parsed.c \
	  parselc.c \
	  parsels.c \
	  parseo.c \
	  parsep.c \
	  parseprc.c \
	  parses.c \
	  parseu.c \
	  parsex.c \
	  ft_strsub.c \

OBJ = $(patsubst %.c,%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c 
	 gcc -Wall -Wextra -Werror -c $? -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
