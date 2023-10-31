#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    public:
        Contact arr[8];
        int     count;
        PhoneBook();
        ~PhoneBook();
};

#endif