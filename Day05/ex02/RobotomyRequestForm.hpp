#ifndef _ROBOTOMYREQUESTFORM_HPP
#define _ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        ;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm( const RobotomyRequestForm & );
        void    operator=( const RobotomyRequestForm & );
        ~RobotomyRequestForm();
        
        class   UnsignedFormException : public std::exception
        {
            virtual const char *what() const throw();
        };
        RobotomyRequestForm(std::string Target);
        virtual void    execute(Bureaucrat const & executor) const;

};

#endif