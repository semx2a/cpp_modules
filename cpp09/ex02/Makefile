# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 16:44:21 by seozcan           #+#    #+#              #
#    Updated: 2023/09/11 16:57:20 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S	= src/
O	= obj/
I	= inc/

CXXFLAGS += -I $I

include settings.mk

OBJ	= $(SRC:$S%=$O%.o)

RM	= /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ) : | $O

$(OBJ) : $O%.o : $S%
	$(CXX) $(CXXFLAGS) -g3 -MMD -c $< -o $@

$(NAME): $(OBJ) $(DEP)
	$(CXX) $(CXXFLAGS) -g3 $^ -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ)) 

cleanobjdir: cleanobj
	$(RM) $O

clean: cleanobjdir 

fclean: clean
	$(RM) $(NAME)

re: fclean all

include custom_rules.mk