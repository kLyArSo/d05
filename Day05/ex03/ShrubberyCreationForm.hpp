#ifndef _SHRUBBERYCREATIONFORM_HPP
#define _SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public Form
{
    private:
        ;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm( const ShrubberyCreationForm & );
        void    operator=( const ShrubberyCreationForm & );
        ~ShrubberyCreationForm();
        
        class   UnsignedFormException : public std::exception
        {
            virtual const char *what() const throw();
        };
        ShrubberyCreationForm(std::string Target);
        virtual void    execute(Bureaucrat const & executor) const;

};

void    tree_one(std::ofstream&    outfile);
void    tree_two(std::ofstream&    outfile);
void    tree_three(std::ofstream&    outfile);
void    tree_four(std::ofstream&   outfile);
#endif