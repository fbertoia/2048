# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bteissei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 03:55:03 by bteissei          #+#    #+#              #
#    Updated: 2018/01/07 15:29:36 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048
CC = gcc -l ncurses
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes -I./libft/
DIR_GAME = srcs
INCLUDES = includes
SRCS_GAME = $(addprefix $(DIR_GAME)/, main.c move.c move2.c print.c misc.c \
check.c menu.c multiply.c color.c movebot.c movetop.c checkdiff.c checkkey.c \
checkmove.c checkwin.c freeoldtab.c printrules.c printusage.c main2048.c \
mainloop.c duptab.c initboard.c setwin.c check_screen.c)

OBJS_GAME = $(SRCS_GAME:$(DIR_GAME)/%.c=$(DIR_GAME)/%.o)

all: library $(NAME)

library: $(OBJS_GAME)
	make -C libft

$(NAME): $(OBJS_GAME) $(INCLUDES)
	$(CC) $(CFLAGS) $(CPPFLAGS) libft/libft.a $(OBJS_GAME) -o $@

$(DIR_GAME)/%.o: $(DIR_GAME)/%.c 
	 gcc -o $@ -c $(CFLAGS) $(CPPFLAGS) $?

clean :
	$(MAKE) -C libft/ clean
	rm -f $(OBJS_GAME)

fclean : clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re : fclean all
