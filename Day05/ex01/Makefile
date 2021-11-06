SRCS = main.cpp\
		Bureaucrat.cpp\
			Form.cpp\

FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = ex01

all : $(NAME)

$(NAME) : $(SRCS)
	clang++ $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -Rf $(NAME)

fclean : clean

re: fclean all