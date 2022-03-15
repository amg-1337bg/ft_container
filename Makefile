
all:
<<<<<<< HEAD
	clang++ -Wall -Wextra -Werror -std=c++98 main.cpp
=======
	clang++ -g -fsanitize=address  -Wall -Wextra -Werror -std=c++98 -lcurses main.cpp
>>>>>>> d26b8ab0a32f8901ca8baec7196803f372f45d0f
