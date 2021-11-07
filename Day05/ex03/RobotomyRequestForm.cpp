#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequestForm", 72, 45)
{
    Form::set_target("Default");
    std::cout << "RR Form Default Constructor Invoked!\n";
}
RobotomyRequestForm::RobotomyRequestForm(std::string Target)
: Form("RobotomyRequestForm", 72, 45)
{
    std::cout << "RR Form Costum Constructor Invoked!\n";
    Form::set_target(Target);
}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & other)
: Form(other.getName(), other.getMin_Grade_Sign(), other.getMin_Grade_Exec())
{
    std::cout << "RR Form Copy Constructor Invoked!\n";
    this->setStatus(other.getStatus());
    Form::set_target(other.Form::get_target());
}

void    RobotomyRequestForm::operator=( const RobotomyRequestForm & keda)
{
    std::cout << "RR Assignment Operator Overload Invoked!\n";
    this->setStatus(keda.getStatus());
    Form::set_target(keda.Form::get_target());
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RR Form Default Destructor Invoked!\n";
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (Form::getStatus() == 0)
        throw(UnsignedFormException());//Throw Unsigned form exception;
    if (Form::getStatus() == 1
    && executor.getGrade() > Form::getMin_Grade_Exec())
        throw(Form::GradeTooLowException());//Throw Grade too low exception
    {
        std::cout << "Drilling Noizzzzzzz....\n";
        static bool kda;
        if (kda == 0)
        {
            std::cout << Form::get_target() << " has been robotomized successfully !" << std::endl;
            kda = 1;
        }
        else if (kda == 1)
        {
            std::cout << Form::get_target() << " is a Failure !" << std::endl;
            kda = 0;
        }
    }
}
const char* RobotomyRequestForm::UnsignedFormException::what() const throw()
{
    return ("UnsignedFormException");
}