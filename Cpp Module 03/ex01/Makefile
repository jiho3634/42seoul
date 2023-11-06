CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
HEADER = ClapTrap.hpp ScavTrap.hpp

NAME = ex01

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	@#

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
