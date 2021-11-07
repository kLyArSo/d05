SRCS = main.cpp\
		Bureaucrat.cpp\
			Form.cpp\
				PresidentialPardonForm.cpp\
					RobotomyRequestForm.cpp\
						ShrubberyCreationForm.cpp\
							Intern.cpp\

FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = ex03

all : $(NAME)

$(NAME) : $(SRCS)
	clang++ $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -Rf $(NAME)

fclean : clean

re: fclean all