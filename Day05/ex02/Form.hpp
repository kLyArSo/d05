#ifndef _FORM_HPP
#define _FORM_HPP
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
class Bureaucrat;
class Form
{
    private:
        const std::string   Name;
        bool                Status;
        std::string         Target;
        const int           Min_Grade_Sign;
        const int           Min_Grade_Exec;
    public:
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        Form();
        Form(const Form &othr);
        void    operator=(const Form &othr);
        ~Form();

        std::string     getName() const ;
        bool            getStatus() const ;
        std::string     get_target() const ;
        void            set_target(std::string );
        int             getMin_Grade_Sign() const;
        int             getMin_Grade_Exec() const;
        Form(std::string , int , int);
        void    beSigned( Bureaucrat& obj);
        void    setStatus(bool x);
        virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream&    operator<<(std::ostream& os, const Form& obj);

#endif