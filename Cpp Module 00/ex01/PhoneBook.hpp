#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
        Contact arr[8];
        int     count;
    public:
        PhoneBook();
        ~PhoneBook();
		int		getCount();
		void	add();
		void	printTable();
		void	printInfo();
};

#endif
