#include "Intern.hpp"
Intern::Intern()
{
    std::cout << "Intern Default Constructor Invoked!" << std::endl;
}
Intern::Intern(const Intern&)
{
    std::cout << "Intern Copy Constructor Invoked!" << std::endl;
}
void    Intern::operator=(const Intern&)
{
    std::cout << "Intern Assignement Operator Invoked!" << std::endl;
}
Intern::~Intern()
{
    std::cout << "Intern Default Destructor Invoked!" << std::endl;
}

Form*   create_SCF(std::string FormTarget)
{
    return (new ShrubberyCreationForm(FormTarget));
}
Form*   create_PPF(std::string FormTarget)
{
    return (new PresidentialPardonForm(FormTarget));
}
Form*   create_RRF(std::string FormTarget)
{
    return (new RobotomyRequestForm(FormTarget));
}
Form* Intern::makeForm(std::string FormName, std::string FormTarget)
{
    std::string FormTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form* (*FormCreator[3]) (std::string);
    FormCreator[0] = &create_SCF;
    FormCreator[1] = &create_RRF;
    FormCreator[2] = &create_PPF;
    for(int i = 0; i < 3; i++)
    {
        if (FormTypes[i] == FormName)
        {
            std::cout << "Intern creates ";
            std::cout << FormName << std::endl;
            return (FormCreator[i](FormTarget));
        }
    }
    std::cout << "Error : Unknown Form Type!"<< std::endl;
    return (NULL);    
}