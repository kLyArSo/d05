#include "Form.hpp"
int     main()
{
    try
    {
        Form    Contract("Employment_Contract", 1, 150);
        std::cout << Contract << std::endl;
        std::cout << "--------------------------------\n";
        Bureaucrat  Boss("Boss", 1);
        std::cout << Boss << std::endl;
        Boss.signForm(Contract);
        std::cout << Contract << std::endl;
        std::cout << "--------------------------------\n";
        Bureaucrat  Employee("Employee", 150);
        Employee.signForm(Contract);
        std::cout << Contract << std::endl;
        std::cout << "--------------------------------\n";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
