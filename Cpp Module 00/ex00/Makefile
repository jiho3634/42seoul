NAME			=	megaphone

SRC				=	$(shell ls | grep -E ".+\.cpp")
HEADER			=	$(shell ls | grep -E ".+\.hpp")
CC				=	c++
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98

all				:	$(NAME)

$(NAME)			:	$(SRC) $(HEADER)
					$(CC) $(CXXFLAGS) $(SRC) -o $(NAME)

clean			:
					@#nothing

fclean			:	clean
					rm -rf $(NAME)

re				:	fclean all

.PHONY			:	all fclean clean re
