#ifndef _BUREAUCRAT_HPP
#define _BUREAUCRAT_HPP
#include "Form.hpp"
#include <iostream>
#include <string>

class Form;
class Bureaucrat
{
    private:
        const std::string   Name;
        int                 Grade;
    public:
        class   GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class   GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        std::string getName( void ) const;
        int         getGrade( void ) const;

        void    promotion();
        void    demotion();
        void    signForm(Form& obj);

        Bureaucrat();
        Bureaucrat(const Bureaucrat &);
        void    operator=(const Bureaucrat &);
        ~Bureaucrat();
        Bureaucrat(std::string Name, int Grade);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& obj);
#endif