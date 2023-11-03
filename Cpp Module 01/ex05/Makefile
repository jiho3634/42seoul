NAME	=	Harl
SRC		=	main.cpp Harl.cpp Map.cpp
HEADER	=	Harl.hpp Map.hpp

all		:	$(NAME)
$(NAME)	:	$(SRC) $(HEADER)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)
clean	:
	@#
fclean	:	clean
	rm $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re
