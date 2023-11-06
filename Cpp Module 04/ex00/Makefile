CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = ex00
SOURCES = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	@#
fclean: clean
	rm -f $(NAME)
re: fclean all