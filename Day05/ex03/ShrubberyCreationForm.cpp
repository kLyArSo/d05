#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreation", 145, 137)
{
    std::cout << "SC Form Default Constructor Invoked!\n";
    Form::set_target("Default");
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string Target)
: Form("ShrubberyCreation", 145, 137)
{
    std::cout << "SC Form Costum Constructor Invoked!\n";
    Form::set_target(Target);
}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & other)
: Form(other.getName(), other.getMin_Grade_Sign(), other.getMin_Grade_Exec())
{
    std::cout << "SC Form Copy Constructor Invoked!\n";
    this->setStatus(other.getStatus());
    Form::set_target(other.Form::get_target());
}

void    ShrubberyCreationForm::operator=(const ShrubberyCreationForm & keda)
{
    std::cout << "SC Assignment Operator Overload Invoked!\n";
    this->setStatus(keda.getStatus());
    Form::set_target(keda.Form::get_target());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "SC Form Default Destructor Invoked!\n";
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (Form::getStatus() == 0)
        throw(UnsignedFormException());//Throw Unsigned form exception;
    if (Form::getStatus() == 1
    && executor.getGrade() > Form::getMin_Grade_Exec())
        throw(Form::GradeTooLowException());//Throw Grade too low exception
    {
        std::ofstream    outfile(Form::get_target() + "_shrubbery");
        tree_one(outfile);
        outfile << "\n\n\n\n\n\n";
        tree_two(outfile);
        outfile << "\n\n\n\n\n\n";
        tree_three(outfile);
        outfile << "\n\n\n\n\n\n";
        tree_four(outfile);
        outfile.close();
    }
}

const char* ShrubberyCreationForm::UnsignedFormException::what() const throw()
{
    return ("UnsignedFormException");
}

void    tree_one(std::ofstream&    outfile)
{       
    outfile << "       /\\      \n";
    outfile << "      /\\*\\     \n";
    outfile << "     /\\O\\*\\    \n";
    outfile << "    /*/\\/\\/\\   \n";
    outfile << "   /\\O\\/\\*\\/\\  \n";
    outfile << "  /\\*\\/\\*\\/\\/\\ \n";
    outfile << " /\\O\\/\\/*/\\/O/\\\n";
    outfile << "       ||      \n";
    outfile << "       ||      \n";
    outfile << "       ||      \n";
}

void    tree_two(std::ofstream&    outfile)
{
    outfile << "         v" << std::endl;
    outfile << "        >X<" << std::endl;
    outfile << "         A" << std::endl;
    outfile << "        d$b" << std::endl;
    outfile << "      .d\\$$b." << std::endl;
    outfile << "    .d$i$$\\$$b." << std::endl;
    outfile << "       d$$@b" << std::endl;
    outfile << "      d\\$$$ib" << std::endl;
    outfile << "    .d$$$\\$$$b" << std::endl;
    outfile << "  .d$$@$$$$\\$$ib." << std::endl;
    outfile << "      d$$i$$b" << std::endl;
    outfile << "     d\\$$$$@$b" << std::endl;
    outfile << "  .d$@$$\\$$$$$@b." << std::endl;
    outfile << ".d$$$$i$$$\\$$$$$$b." << std::endl;
    outfile << "        ###" << std::endl;
    outfile << "        ###" << std::endl;
    outfile << "        ###" << std::endl;
}

void    tree_three(std::ofstream&    outfile)
{
    outfile << "             /\\" << std::endl;
    outfile << "            <  >" << std::endl;
    outfile << "             \\/" << std::endl;
    outfile << "             /\\" << std::endl;
    outfile << "            /  \\" << std::endl;
    outfile << "           /++++\\" << std::endl;
    outfile << "          /  ()  \\" << std::endl;
    outfile << "          /      \\" << std::endl;
    outfile << "         /~`~`~`~`\\" << std::endl;
    outfile << "        /  ()  ()  \\" << std::endl;
    outfile << "        /          \\" << std::endl;
    outfile << "       /*&*&*&*&*&*&\\" << std::endl;
    outfile << "      /  ()  ()  ()  \\" << std::endl;
    outfile << "      /              \\" << std::endl;
    outfile << "     /++++++++++++++++\\" << std::endl;
    outfile << "    /  ()  ()  ()  ()  \\" << std::endl;
    outfile << "    /                  \\" << std::endl;
    outfile << "   /~`~`~`~`~`~`~`~`~`~`\\" << std::endl;
    outfile << "  /  ()  ()  ()  ()  ()  \\" << std::endl;
    outfile << "  /*&*&*&*&*&*&*&*&*&*&*&\\" << std::endl;
    outfile << " /                        \\" << std::endl;
    outfile << "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\" << std::endl;
    outfile << "           |   |" << std::endl;
    outfile << "          |`````|" << std::endl;
    outfile << "          \\_____/" << std::endl;
}

void    tree_four(std::ofstream&    outfile)
{
    outfile << "          .     .  .      +     .      .          ." << std::endl;
    outfile << "    .       .      .     #       .           ." << std::endl;
    outfile << "       .      .         ###            .      .      ." << std::endl;
    outfile << "     .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
    outfile << "         .      . \"####\"###\"####\"  ." << std::endl;
    outfile << "      .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
    outfile << " .             \"#########\"#########\"        .        ." << std::endl;
    outfile << "       .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
    outfile << "    .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
    outfile << "               .\"##\"#####\"#####\"##\"           .      ." << std::endl;
    outfile << "   .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
    outfile << "     .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
    outfile << "   .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
    outfile << "           .     \"      000      \"    .     ." << std::endl;
    outfile << "      .         .   .   000     .        .       ." << std::endl;
    outfile << ". .. ..................O000O........................ ...... ..." << std::endl;
}