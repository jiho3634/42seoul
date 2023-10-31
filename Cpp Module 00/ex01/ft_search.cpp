#include "ex01.hpp"
#include <iomanip>

void    ft_column_name()
{
    std::cout << "     index|first name| last name|  nickname" << std::endl;
}

void    ft_table(PhoneBook *PhoneBook)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (PhoneBook->arr[i].index == 0)
            break ;
        std::cout << std::setw(10) << std::right << PhoneBook->arr[i].index; 
        std::cout << "|";
        if (PhoneBook->arr[i].first.size() > 10)
            std::cout << PhoneBook->arr[i].first.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << std::right << PhoneBook->arr[i].first; 
        std::cout << "|";
        if (PhoneBook->arr[i].last.size() > 10)
            std::cout << PhoneBook->arr[i].last.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << std::right << PhoneBook->arr[i].last; 
        std::cout << "|";
        if (PhoneBook->arr[i].nickname.size() > 10)
            std::cout << PhoneBook->arr[i].nickname.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << std::right << PhoneBook->arr[i].nickname; 
        std::cout << "\n";
        i++;
    }
}

void    ft_information(PhoneBook *PhoneBook)
{
    std::string index;
    int         intex;

    while (1)
    {
        std::cout << "Please, enter the index that you want: ";
        std::getline(std::cin, index);
        intex = std::stoi(index);
        if ((intex >= 1 && intex <= 8) && intex <= PhoneBook->count)
        {
            intex--;
            std::cout << "FirstName : " << PhoneBook->arr[intex].first << std::endl;
            std::cout << "Last Name : " << PhoneBook->arr[intex].last << std::endl;
            std::cout << "Nick Name : " << PhoneBook->arr[intex].nickname << std::endl;
            std::cout << "Phone Num : " << PhoneBook->arr[intex].number << std::endl;
            std::cout << "   Secret : " << PhoneBook->arr[intex].secret << std::endl;
            break ;
        }
        else
            std::cout << "Wrong Number\n";
    }
}

void    ft_search(PhoneBook *PhoneBook)
{
    ft_column_name();
    ft_table(PhoneBook);
    ft_information(PhoneBook);
}
