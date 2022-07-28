# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:19:37 by aminoru-          #+#    #+#              #
#    Updated: 2022/04/28 00:06:02 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test

SRCS = test.c 
LIB = ../libft.a
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} 
				
clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all