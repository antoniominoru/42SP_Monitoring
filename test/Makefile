# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:19:37 by aminoru-          #+#    #+#              #
#    Updated: 2022/07/30 21:51:40 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test

LIBFTPRINTHPATH = ../lib/printf/
LIBFTPRINTH = ../lib/printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCS = -I ./include/ -I ../include/ 
SRCS = test.c \
		../src/utils/db_valid.c

OBJS = ${SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
				make -C $(LIBFTPRINTHPATH)
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFTPRINTH} 

.c.o:
				${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

clean:
				make clean -C ../lib/printf
				rm -f ${OBJS}

fclean:		clean
				make fclean -C ../lib/printf
				rm -f ${NAME}

re:			fclean all