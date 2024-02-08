# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PATHS::

PROJ	:=	

ODIR	:=	objs

SDIR	:=	src

IDIR	:=	inc

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	:=	Array

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCES::

SRC	:=	main.cpp
			
OBJS	=	$(addprefix $(ODIR)/, $(SRC:.cpp=.o))

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CPP		:=	c++

WFLAGS	:=	-MMD -Wall -Wextra -Werror -std=c++98

WCONV	:=	-Wconversion

GFLAG	:=	-g3

SANFLAG	:=	-fsanitize=address

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COLORS::

RESET		=	\033[m

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE 		 	=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
WHITE			= 	\033[0;37m

# High Intensty
HIGREEN			=	\033[0;92m
HIORANGE	 	=	\033[0;93m
HIPURPLE		=	\033[0;95m

# Bold
BORANGE 		=	\033[1;33m
BBLUE			=	\033[1;34m
BPURPLE			=	\033[1;35m
BCYAN			=	\033[1;36m

# Bold High Intensity
BHIGREEN		=	\033[1;92m
BHIORANGE	 	=	\033[1;93m
BHIPURPLE		=	\033[1;95m

# Italic
ICYAN			=	\033[3;36m

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARAMS::

INCLUDE_FLAGS		= $(addprefix -I , $(IDIR))
DEPS				= $(OBJS:.o=.d)

vpath %.cpp $(SDIR)
vpath %.o $(ODIR)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MANDATORY::

all:			header h2 message $(NAME)

$(ODIR)/%.o:	%.cpp
	@$(CPP) $(WFLAGS) $(GFLAG) $(INCLUDE_FLAGS) -c $< -o $@ 
	@echo "$(HIGREEN)compilation:[OK]$(RESET)" | awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'

$(NAME):		$(OBJS)	
	@$(CPP) $(WFLAGS) $(GFLAG) $(OBJS) -o $(NAME)
	@echo "$(HIGREEN)mandatory exe:[OK]$(RESET)" | awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'

$(OBJS):		| $(ODIR)

$(ODIR):
	@mkdir -p $(ODIR)
	@echo "$(HIGREEN)objs folder:[OK]$(RESET)" | awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'
	

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

update:		header fclean
	@git pull

push:		header fclean
	@echo "$(HIGREEN)"
	@git add .
	@git commit --quiet
	@git push --quiet
	@echo "$(HIGREEN)git push:[OK]$(RESET)" | awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'

clean:		header
	@rm -rf $(ODIR)
	@echo "$(HIORANGE)objs folder:[RM]$(RESET)" | awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'

fclean:		header clean
	@rm -f $(NAME)
	@echo "$(HIORANGE)$(NAME) bin:[RM]$(RESET)" | awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'

header:
	@echo "$(BHIPURPLE)"
	@echo "   ______________________________________________________"
	@echo "  /\     __________    ________    ___   ___    _______  \ "
	@echo " /  \   /\         \  /\   __  \  /\  \ /\  \  /\  ____\  \ "
	@echo "/    \  \ \  \ _/\  \ \ \   __  \ \ \  \ /_ /_ \ \  _\_/_  \ "
	@echo "\     \  \ \__\_/ \__\ \ \__\-\__\ \ \__\  \__\ \ \______\  \ "
	@echo " \     \  \/__/  \/__/  \/__/ /__/  \/__/ \/__/  \/______/   \ "
	@echo "  \     \_____________________________________________________\ "
	@echo "   \    /                                                     / "
	@echo "    \  /                   $(CYAN)S E O Z C A N           \$(RESET)$(BHIPURPLE)   ____   / "
	@echo "     \/______________________________________________/\   \_/ "
	@echo "                                                     \ \___\ "
	@echo "                                                      \/___/ "
	@echo "$(RESET)"

h2:
	@echo "\n$(BHIPURPLE):::::::::::::::::::::::::::::::::::::::::::::::::::::::CPP::\n$(RESET)"

message:
	@make -q $(NAME) && echo "$(BHIGREEN)All files are already up to date$(RESET)" || true

re:		header fclean 
	@make all 

-include $(DEPS)

.PHONY:	all bonus clean fclean re push update o_dir h1 h2 header 
