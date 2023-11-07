CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
HEADER = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp
NAME = ex03

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	@#

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
