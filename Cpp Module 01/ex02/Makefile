NAME	=	HI_THIS_IS_BRAIN
SRC		=	main.cpp
all		:	$(NAME)	
$(NAME)	:	$(SRC)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)
clean	:
	@#
fclean	: clean
	rm $(NAME)
re		: fclean all
.PHONY	:	all clean fclean re
