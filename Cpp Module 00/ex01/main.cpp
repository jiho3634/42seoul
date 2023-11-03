#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;

	while (1) {
		std::cout << "Please, enter one of: ADD, SEARCH, EXIT: ";
		std::getline (std::cin, command);
		if (std::cin.eof()) {
			clearerr(stdin);
			std::cin.clear();
			break ;
		}
		if (command.empty())
			continue ;
		if (command.compare("EXIT") == OK)
			break ;
		else if (command.compare("ADD") == OK)
			PhoneBook.add();
		else if (command.compare("SEARCH") == OK) {
			if (PhoneBook.getCount() == 0) {
				std::cout << "No Contact\n";
				continue ;
			}
			PhoneBook.printTable();
			PhoneBook.printInfo();
		}
		else
			continue ;
	}
	return (0);
}
