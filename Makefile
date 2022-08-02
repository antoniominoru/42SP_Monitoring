# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/08/03 01:30:51 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = monitoring

LIBPATH = ./lib/printf
LIB = ./lib/printf/libftprintf.a

CC = gcc
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include/
SRCS = 	./src/monitoring.c \
		./src/utils/db_load.c \
		./src/utils/db_valid.c \
		./src/utils/error.c \
		./src/utils/timer_select.c \
		./src/utils/db_monit.c \
		./src/utils/free.c \
		./src/utils/select_protocol.c

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

git:
			echo > ./log/monitoring.log
			make re
			make fclean -C ./lib/printf
			make clean
			clear
			git add .
			git commit -m "ping_select + dns_select"
			git push

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
