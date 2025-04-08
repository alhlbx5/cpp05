# Compiler and Flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I.

# Source Files
SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Executable Name
NAME = abstract_form_test

# Header Files (for dependency tracking, optional but good practice)
HDRS = Bureaucrat.hpp \
       AForm.hpp \
       ShrubberyCreationForm.hpp \
       RobotomyRequestForm.hpp \
       PresidentialPardonForm.hpp

# Default Rule: Build the executable
all: $(NAME)

# Rule to link the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Executable '$(NAME)' created."

# Rule to compile source files into object files
# Example with explicit dependencies (repeat for all .cpp files)
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to remove object files
clean:
	rm -f $(OBJS)
	@echo "Object files removed."

# Rule to remove object files and the executable
fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery # Clean up generated shrubbery files
	@echo "Executable '$(NAME)' and shrubbery files removed."

# Rule to recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
