# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 16:20:20 by oalketbi          #+#    #+#              #
#    Updated: 2022/02/16 16:20:35 by oalketbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c operations.c check.c simple_sort.c sort.c sorted_array.c \
	utils.c
OBJ = $(SRC:.c=.o)
SRCB = checker_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	operations.c check.c simple_sort.c sort.c sorted_array.c \
	utils.c
OBJB = $(SRCB:.c=.o)
LIBF = ./libft
LIB = libft.a


%.o: %.c
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
	
$(NAME): ${OBJ}
	make bonus -C ${LIBF}
	gcc ${FLAGS} -o ${NAME} ${OBJ} -L ${LIBF} -lft
all: $(NAME)

clean:
	rm -f ${OBJ}
	rm -f ${OBJB}
	make clean -C ${LIBF}
fclean: clean
	rm -f ${NAME}
	rm -f ${B_NAME}
	make fclean -C ${LIBF}
bonus: $(NAME) ${OBJB}
	gcc ${FLAGS} -o ${B_NAME} ${OBJB} -L ${LIBF} -lft
re: fclean all
