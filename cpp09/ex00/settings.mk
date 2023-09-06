ifndef SETTINGS_MK
	SETTINGS_MK = 1

NAME	= btc
SRC		= $Smain.cpp \
			$SBitcoinExchange.cpp

CC 		= c++
CFLAGS	+= -Wall -Werror -Wextra -std=c++98
LDFLAGS	+=

endif