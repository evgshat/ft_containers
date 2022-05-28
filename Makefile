NAME	= ft_containers
SRCS	= test_for_stack.cpp
OBJ		= $(SRCS: cpp=.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f
HEADERS = ft_stack.hpp

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
