CC = g++
# CFLAGS = -Wall -Wextra -Werror -g -pedantic -std=c++11 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g -pedantic -std=c++11 
SRCS = $(wildcard *.cpp) 
OBJS = $(patsubst %.cpp,obj/%.o,$(SRCS))

TARGET = PmergeMe

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo "$(GREEN)Compiled PmergeMe!$(DEFAULT)"

obj/%.o: %.cpp | obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj:
	@mkdir -p obj

clean:
	@$(RM) -r obj/
	@echo "$(YELLOW)Removed all objects!$(DEFAULT)"

fclean: clean
	@$(RM) $(TARGET)
	@echo "$(RED)Removed PmergeMe!$(DEFAULT)"

re: fclean all

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
