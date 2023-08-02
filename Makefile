# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 11:22:40 by databey           #+#    #+#              #
#    Updated: 2023/07/29 11:22:43 by databey          ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCF = ./src/

DOTC = $(SRCF)main.c $(SRCF)utils.c $(SRCF)logic.c $(SRCF)error.c $(SRCF)helpers.c

DOTO = 	$(addprefix outputs/,$(notdir $(DOTC:.c=.o)))

INC = ./headers/

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(DOTO)
	gcc $(FLAG) -o $(NAME) $(DOTO) 

outputs/%.o: src/%.c
	gcc -c $(FLAG) -o $@ $< -I $(INC)

clean:
	/bin/rm $(DOTO)

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
