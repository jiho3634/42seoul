NAME	=	BraiiiiiiinnnzzzZ
SRC		=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
Header	=	Zombie.hpp
CC		=	c++
CXXFLAG	=	-std=c++98 -Wall -Wextra -Werror

all		:	$(NAME)
	
$(NAME)	:	$(SRC) $(HEADER)
	$(CC) $(CXXFLAG) $(SRC) -o $(NAME)
clean	:
	@#
fclean	:	clean
	rm $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re
