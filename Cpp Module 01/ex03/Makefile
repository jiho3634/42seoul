NAME	=	Unnecessary_violence
SRC		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADER	=	Weapon.hpp HumanA.hpp HumanB.hpp
all		:	$(NAME)
$(NAME)	:	$(SRC) $(HEADER)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)
clean	:
	@#
fclean	:	clean
	rm $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re
