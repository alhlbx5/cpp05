CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I.

SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp \
       Intern.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = intern_test 

HDRS = Bureaucrat.hpp \
       AForm.hpp \
       ShrubberyCreationForm.hpp \
       RobotomyRequestForm.hpp \
       PresidentialPardonForm.hpp \
       Intern.hpp 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Executable '$(NAME)' created."

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery # Clean up generated shrubbery files
	@echo "Executable '$(NAME)' and shrubbery files removed."

re: fclean all

.PHONY: all clean fclean re
