NAME = test
SRCS = test.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
TEST_HEADERS = test.hpp
PROJECTS_HEADERS = ft_containers.hpp
PROJECT_DIR = $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))/..))
FLAGS = -Wall -Werror -Wextra -std=c++17 -g
CC = clang++
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I $(PROJECT_DIR) $(OBJS) -o $@

%.o: %.cpp $(TEST_HEADERS) Makefile
	$(CC) $(FLAGS) -I $(PROJECT_DIR) -c $< -c $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
