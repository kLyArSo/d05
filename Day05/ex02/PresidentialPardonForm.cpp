#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonForm", 25, 5)
{
    std::string Target = "Default";
    std::cout << "PP Form Default Constructor Invoked!\n";
}
PresidentialPardonForm::PresidentialPardonForm(std::string Target)
: Form("PresidentialPardonForm", 25, 5)
{
    std::cout << "PP Form Costum Constructor Invoked!\n";
    Form::set_target(Target);
}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & other)
: Form(other.getName(), other.getMin_Grade_Sign(), other.getMin_Grade_Exec())
{
    std::cout << "PP Form Copy Constructor Invoked!\n";
    this->setStatus(other.getStatus());
    Form::set_target(other.Form::get_target());
}

void    PresidentialPardonForm::operator=( const PresidentialPardonForm & keda)
{
    std::cout << "PP Assignment Operator Overload Invoked!\n";
    this->setStatus(keda.getStatus());
    Form::set_target(keda.Form::get_target());
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PP Form Default Destructor Invoked!\n";
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (Form::getStatus() == 0)
        throw(UnsignedFormException());//Throw Unsigned form exception;
    if (Form::getStatus() == 1
    && executor.getGrade() > Form::getMin_Grade_Exec())
        throw(Form::GradeTooLowException());//Throw Grade too low exception
    {
        std::cout << Form::get_target() << " has been pardoned by Zafod Beeblebrox!\n";
    }
}
const char* PresidentialPardonForm::UnsignedFormException::what() const throw()
{
    return ("UnsignedFormException");
}