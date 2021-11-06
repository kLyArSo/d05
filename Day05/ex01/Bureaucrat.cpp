#include "Bureaucrat.hpp"
#include "Form.hpp"
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


void    Bureaucrat::signForm(Form& obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << this->getName();
        std::cout << " signs ";
        std::cout << obj.getName();
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->getName();
        std::cout << " cannot sign ";
        std::cout << obj.getName();
        std::cout << " because ";
        std::cout << e.what();
        std::cout << ".";
        std::cout << std::endl;
    }
}

/*-----------------CANON---------------------*/

Bureaucrat::Bureaucrat()
: Name("Nobody"), Grade(150)
{
    std::cout << "Bureaucrat Default Constructor Invoked!" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
: Name(other.Name), Grade(other.Grade)
{
    std::cout << "Bureaucrat Copy Constructor Invoked!" << std::endl;
    if (this->Grade < 1)
        throw(GradeTooHighException());
    else if (this->Grade > 150)
        throw(GradeTooLowException());
}
void    Bureaucrat::operator=(const Bureaucrat &other)
{
    this->Grade = other.Grade;
    std::cout << "Bureaucrat Assignment Operator Overload Invoked!" << std::endl;
    std::cout << "Name Is a Const Attribut That Can Only Be Initialised!" << std::endl;
    std::cout << "Grade Assigned!" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Default Destructor Invoked!" << std::endl;
}
Bureaucrat::Bureaucrat(std::string Name, int Grade)
: Name(Name), Grade(Grade)
{
    std::cout << "Bureaucrat Custom Constructor Invoked!" << std::endl;
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