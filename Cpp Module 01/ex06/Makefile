NAME = harlFilter
SRC = main.cpp Harl.cpp
HEADER = Harl.hpp
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@#
fclean:
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re