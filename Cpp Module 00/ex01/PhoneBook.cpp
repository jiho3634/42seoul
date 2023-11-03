#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0) {}
PhoneBook::~PhoneBook() {}

int	PhoneBook::getCount() {
	return (count);
}

void    PhoneBook::add()
{
    if (arr[count % 8].add(count % 8))
		return ;
	count++;
}

void    PhoneBook::printTable() {
	std::cout << "     Index|First name| Last name| Nick name" << std::endl;
    for (int i = 0; i < 8; ++i) {
        if (arr[i].getIndex() == 0)
            break ;
		else
			arr[i].printTable();
	}
}

void    PhoneBook::printInfo()
{
    std::string index;
    int         intex;

    while (1)
    {
        std::cout << "Please, enter the index that you want: ";
        std::getline(std::cin, index);
		if (std::cin.eof()) {
			clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			break ;
		}
		if (index.empty())
			continue ;
        intex = std::atoi(index.c_str());
        if ((intex >= 1 && intex <= 8) && intex <= count) {
            arr[intex - 1].printInfo();
            break ;
        }
        else
            std::cout << "Wrong Number\n";
    }
}
