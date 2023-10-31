#include "ex01.hpp"

void    ft_add(PhoneBook *PhoneBook)
{
    std::string first;
    std::string last;
    std::string nickname;
    std::string number;
    std::string secret;

    PhoneBook->arr[PhoneBook->count % 8].index = PhoneBook->count % 8 + 1;
    while (first.empty())
    {
        std::cout << "Please, enter the first name: ";
        std::getline (std::cin, first);
    }
    PhoneBook->arr[PhoneBook->count % 8].first = first;
    while (last.empty())
    {
        std::cout << "Please, enter the last name: ";
        std::getline (std::cin, last);
    }
    PhoneBook->arr[PhoneBook->count % 8].last = last;
    while (nickname.empty())
    {
        std::cout << "Please, enter the nickname: ";
        std::getline (std::cin, nickname);
    }
    PhoneBook->arr[PhoneBook->count % 8].nickname = nickname;
    while (number.empty())
    {
        std::cout << "Please, enter the phone number: ";
        std::getline (std::cin, number);
    }
    PhoneBook->arr[PhoneBook->count % 8].number = number;
    while (secret.empty())
    {
        std::cout << "Please, enter the darkest secret: ";
        std::getline (std::cin, secret);
    }
    PhoneBook->arr[PhoneBook->count % 8].secret = secret;
    PhoneBook->count++;
}
