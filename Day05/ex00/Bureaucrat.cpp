#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade_Too_High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade_Too_Low!");
}
std::string Bureaucrat::getName( void ) const
{
    return (this->Name);
}
int         Bureaucrat::getGrade( void ) const
{
    return (this->Grade);
}
void    Bureaucrat::promotion()
{
    if (this->Grade == 1)
        throw(Bureaucrat::GradeTooHighException());
    this->Grade--;
}
void    Bureaucrat::demotion()
{
    if (this->Grade == 150)
        throw(Bureaucrat::GradeTooLowException());
    this->Grade++;
}

/*-----------------CANON---------------------*/

Bureaucrat::Bureaucrat()
: Name("Nobody"), Grade(150)
{
    std::cout << "Default Constructor Invoked!" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
: Name(other.Name), Grade(other.Grade)
{
    std::cout << "Copy Constructor Invoked!" << std::endl;
    if (this->Grade < 1)
        throw(GradeTooHighException());
    else if (this->Grade > 150)
        throw(GradeTooLowException());
}
void    Bureaucrat::operator=(const Bureaucrat &other)
{
    this->Grade = other.Grade;
    std::cout << "Assignment Operator Overload Invoked!" << std::endl;
    std::cout << "Name Is a Const Attribut That Can Only Be Initialised!" << std::endl;
    std::cout << "Grade Assigned!" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Destructor Invoked!" << std::endl;
}
Bureaucrat::Bureaucrat(std::string Name, int Grade)
: Name(Name), Grade(Grade)
{
    std::cout << "Custom Constructor Invoked!" << std::endl;
    if (this->Grade < 1)
        throw(GradeTooHighException());
    else if (this->Grade > 150)
        throw(GradeTooLowException());
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat& obj)
{
    os << "Name : " << obj.getName();
    os << ".\nGrade = " << obj.getGrade();
    os << ".";
    return (os);
}