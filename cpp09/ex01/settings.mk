ifndef SETTINGS_MK
	SETTINGS_MK = 1

NAME	= RPN
SRC		= $Smain.cpp \
		$SRPN.cpp

CXX			= c++
CXXFLAGS	+= -Wall -Werror -Wextra -std=c++98
LDFLAGS		+=

endif