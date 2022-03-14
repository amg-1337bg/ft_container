
all:
	clang++ -g -fsanitize=address  -Wall -Wextra -Werror -std=c++98 -lcurses main.cpp