CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I. 

SRCS = main.cpp Bureaucrat.cpp Form.cpp 

OBJS = $(SRCS:.cpp=.o)

NAME = form_test 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Executable '$(NAME)' created."


Bureaucrat.o: Bureaucrat.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c Bureaucrat.cpp -o Bureaucrat.o

Form.o: Form.cpp Form.hpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c Form.cpp -o Form.o

main.o: main.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o


clean:
	rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	rm -f $(NAME)
	@echo "Executable '$(NAME)' removed."

re: fclean all

.PHONY: all clean fclean re
