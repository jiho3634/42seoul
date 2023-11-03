NAME	=	Sed_is_for_losers
SRC		=	main.cpp FileReplacer.cpp
HEADER	=	FileReplacer.hpp

all		:	$(NAME)
$(NAME)	:	$(SRC) $(HEADER)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)
clean	:
	@#
fclean	:	clean
	rm $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re
