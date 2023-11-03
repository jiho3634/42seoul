NAME	=	zombieHorde
SRC		=	main.cpp Zombie.cpp zombieHorde.cpp
Header	=	Zombie.hpp

all		:	$(NAME)
	
$(NAME)	:	$(SRC) $(HEADER)
	c++ -std=c++98 -Wall -Wextra -Werror $(SRC) -o $(NAME)
clean	:
	@#
fclean	:	clean
	rm $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re
