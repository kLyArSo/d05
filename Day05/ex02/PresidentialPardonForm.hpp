#ifndef _PRESIDENTIALPARDONFORM_HPP
#define _PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        ;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm( const PresidentialPardonForm & );
        void    operator=( const PresidentialPardonForm & );
        ~PresidentialPardonForm();
        
        class   UnsignedFormException : public std::exception
        {
            virtual const char *what() const throw();
        };
        PresidentialPardonForm(std::string Target);
        virtual void    execute(Bureaucrat const & executor) const;

};
#endif
