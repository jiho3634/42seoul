CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SOURCES = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp
NAME = ex01

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	@#
fclean: clean
	rm -f $(NAME)
re: fclean all