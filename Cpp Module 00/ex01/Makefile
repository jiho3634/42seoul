NAME			=	PhoneBook

SRC				=	$(shell ls | grep -E ".+\.cpp")
HEADER			=	$(shell ls | grep -E ".+\.hpp")
CC				=	c++
CFLAGS			=	-Wall -Werror -Wextra -std=c++98

all				:	$(NAME)

$(NAME)			:	$(SRC) $(HEADER)
					$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean			:
					@#

fclean			:	clean
					rm -rf $(NAME)

re				:	fclean all

.PHONY			:	all fclean clean re
