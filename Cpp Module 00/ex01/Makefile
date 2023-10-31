NAME			=	PhoneBook

SRC				=	$(shell ls | grep -E ".+\.cpp")
HEADER			=	$(shell ls | grep -E ".+\.hpp")
CC				=	g++
CFLAGS			=	-Wall -Werror -Wextra -std=c++98

all				:	$(NAME)

$(NAME)			:	$(SRC) $(HEADER)
					$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean			:	clean
					rm -rf $(NAME)

re				:	fclean all

.PHONY			:	all fclean clean re
