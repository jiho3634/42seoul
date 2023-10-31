#include "ex01.hpp"

int main(void)
{
    PhoneBook   PhoneBook;
    std::string command;

    while (1)
    {
        std::cout << "Please, enter one of: ADD, SEARCH, EXIT: ";
        std::getline (std::cin, command);
        if (command.compare("EXIT") == 0)
            break ;
        else if (command.compare("SEARCH") == 0)
        {
            if (PhoneBook.count == 0)
            {
               std::cout << "No Contact\n";
               continue ;
            }
            ft_search(&PhoneBook);
        }
        else if (command.compare("ADD") == 0)
            ft_add(&PhoneBook);
        else
            continue ;
    }
    return (0);
}