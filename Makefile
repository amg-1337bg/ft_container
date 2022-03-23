
all:
	clang++ -g -fsanitize=address  -Wall -Wextra -Werror  main.cpp
