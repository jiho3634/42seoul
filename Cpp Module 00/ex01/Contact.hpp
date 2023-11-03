#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

#define OK 0

class Contact
{
	private:
		std::string	item[5];
        std::string info[5];
        int         index;
    public:
		int			getIndex();
		int			tmp(int i);
		int			add(int mod);
		void		printTable();
		void		printInfo();
        Contact();
        ~Contact();
};

#endif
