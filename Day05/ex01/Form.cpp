#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form()
: Name("Useless Form"), Status(0), Min_Grade_Sign(150), Min_Grade_Exec(150)
{
    std::cout << "Form Default Constructor Invoked!";
}
Form::Form(std::string N, int MGS, int MGE)
: Name(N), Status(0), Min_Grade_Sign(MGS), Min_Grade_Exec(MGE)
{
    if (MGS < 1 || MGE < 1)
        throw GradeTooHighException();
    if (MGS > 150 || MGE > 150)
        throw GradeTooLowException();
    std::cout << "Form Custom Constructor Invoked!\n";
}
Form::Form(const Form &othr)
: Name(othr.Name), Status(othr.Status)
, Min_Grade_Sign(othr.Min_Grade_Sign), Min_Grade_Exec(othr.Min_Grade_Exec)
{
    if (Min_Grade_Exec < 1 || Min_Grade_Sign < 1)
        throw GradeTooHighException();
    if (Min_Grade_Exec > 150 || Min_Grade_Sign > 150)
        throw GradeTooLowException();
    std::cout << "Form Copy Constructor Invoked!\n";
}
void    Form::operator=(const Form &othr)
{
    std::cout << "Form Assignation Operator Overload Invoked!" << std::endl;
    std::cout << "Constant Attributes Can Only Be Initialized!" << std::endl;
    std::cout << "Signature Status Assigned!" << std::endl;
    this->setStatus(othr.Status);
}
Form::~Form()
{
    std::cout << "Form Default Destructor Invoked!\n";
}

std::string     Form::getName() const
{
    return (this->Name);
}
bool            Form::getStatus() const
{
    return (this->Status);
}
int             Form::getMin_Grade_Sign() const
{
    return (this->Min_Grade_Sign);
}
int             Form::getMin_Grade_Exec() const
{
    return (this->Min_Grade_Exec);
}
void            Form::setStatus(bool x)
{
    this->Status = x;
}
void            Form::beSigned( Bureaucrat& obj)
{
    int grade = obj.getGrade();
    if (grade <= this->getMin_Grade_Sign())
        this->setStatus(1);
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException");
}
const char* Form::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException");
}

std::ostream&    operator<<(std::ostream& os, const Form& obj)
{
    os << "The " ;
    os << obj.getName() ;
    os << ((obj.getStatus() == 1) ? " Form is Signed" : " Form is Not Signed");
    os << std::endl;
    os << "The MGS and MGE are respectively " ;
    os << obj.getMin_Grade_Sign(); 
    os << " " ;
    os << obj.getMin_Grade_Exec();
    os << "." ;
    return (os);
}
