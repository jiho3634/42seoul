#include "Contact.hpp"

Contact::Contact()	:	index(0) {
	item[0] = "First Name";
	item[1] = "Last Name";
	item[2] = "Nick Name";
	item[3] = "Phone Number";
	item[4] = "Darkest Secret";
}

Contact::~Contact() {}

int	Contact::getIndex() {
	return (index);
}

int	Contact::tmp(int i) {
	std::string	input;

	while (input.empty()) {
		std::cout << item[i] << " : ";
		std::getline (std::cin, input);
		if (std::cin.eof()) {
			clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			return (1);
		}
	}
	info[i] = input;
	return (0);
}

int	Contact::add(int mod) {

	index = mod + 1;
	for (int i = 0; i < 5; ++i) {
		if (tmp(i)) {
			for(; i >= 0; --i)
				info[i] = "";
			index = 0;
			return (1);
		}
	}
	return (0);
}


void	Contact::printTable() {
	std::string result;

	std::cout << std::setw(10) << std::right << index;
	std::cout << "|";
	for (int i = 0; i < 3; ++i) {
		result = "";
		for (std::string::size_type j = 0; j < info[i].size(); ++j) {
			if (std::isspace(info[i][j]))
				result +=  ' ';
			else
				result +=  info[i][j];
		}
		if (info[i].size() > 10)
			std::cout << result.substr(0, 9) << ".";
		else 
			std::cout << std::setw(10) << std::right << result;
		if (i != 2)
			std::cout << "|";
		else
			std::cout << "\n";
	}
}

void	Contact::printInfo () {
	for (int i = 0; i < 5; ++i)
		std::cout << item[i] << " : " << info[i] << std::endl;
}
