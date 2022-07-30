# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/07/30 23:12:16 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = monitoring

LIBFTPRINTHPATH = ./lib/printf/
LIBFTPRINTH = ./lib/printf/libftprintf.a

CC = gcc
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include/
SRCS = 	./src/monitoring.c \
		./src/utils/db_load.c \
		./src/utils/db_valid.c \
		./src/utils/error.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPRINTHPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFTPRINTH}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

t:
			make -C ./test
			clear
			./test/run_test

clean:
			make clean -C ./lib/printf
			make clean -C ./test
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./lib/printf
			make fclean -C ./test
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
