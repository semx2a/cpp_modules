ifndef SETTINGS_MK
	SETTINGS_MK = 1

NAME	= PmergeMe
SRC		= $Smain.cpp \
			$SPmergeMe.cpp

CXX			= c++
CXXFLAGS	+= -Wall -Werror -Wextra -std=c++98
LDFLAGS		+=

endif