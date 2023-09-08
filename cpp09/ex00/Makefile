# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 16:44:21 by seozcan           #+#    #+#              #
#    Updated: 2023/09/08 08:46:59 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S	= src/
O	= obj/
I	= inc/

CFLAGS += -I$I

include settings.mk

OBJ	= $(SRC:$S%=$O%.o)

RM	= /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ) : | $O

$(OBJ) : $O%.o : $S%
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ) $(DEP)
	$(CC) $(LDFLAGS) $^ -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ)) 

cleanobjdir: cleanobj
	$(RM) $O

clean: cleanobjdir 

fclean: clean
	$(RM) $(NAME)

re: fclean all

include custom_rules.mk