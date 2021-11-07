#ifndef _INTERN_HPP
#define _INTERN_HPP
#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        ;
    public:
        Intern();
        Intern(const Intern&);
        void    operator=(const Intern&);
        ~Intern();

        Form *makeForm(std::string FormName, std::string FormTarget);
};
#endif