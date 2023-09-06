# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 16:44:21 by seozcan           #+#    #+#              #
#    Updated: 2023/09/06 19:03:58 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S	= src/
O	= obj/
I	= inc/
D	= dep/

CFLAGS += -I$I

include settings.mk

OBJ	= $(SRC:$S%=$O%.o)
DEP = $(SRC:$S%=$O%.d)

RM	= /bin/rm -rf
RMDIR	= /bin/rmdir

.PHONY: all clean fclean re

all: $(NAME)
	
$O:
	@mkdir $@

$(OBJ) : | $O

$(OBJ) : $O%.o : $S%
	$(CC) $(CFLAGS) -c $< -o $@

$D:
	@mkdir $@

$(DEP) : | $D

$(DEP): $D%.d : $S%
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ)) 

cleanobjdir: cleanobj
	$(RMDIR) $O

cleandep:
	$(RM) $(wildcard $(DEP))

cleandepdir: cleandep
	$(RMDIR) $D

clean: cleanobjdir cleandepdir

fclean: clean
	$(RM) $(NAME)

re: fclean all

include $(DEP)

include custom_rules.mk