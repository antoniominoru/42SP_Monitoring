# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/08/01 01:36:44 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = monitoring

LIBPATH = ./lib/pipex/
LIB = ./lib/pipex/lgp_pipex.a

CC = gcc
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include/
SRCS = 	./src/monitoring.c \
		./src/utils/db_load.c \
		./src/utils/db_valid.c \
		./src/utils/error.c \
		./src/utils/timer_select.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIB}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

t:
			make -C ./test
			clear
			./test/run_test

clean:
			make clean -C ./lib/pipex
			make clean -C ./test
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./lib/pipex
			make fclean -C ./test
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
