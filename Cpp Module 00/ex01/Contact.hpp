#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
    public:
        int         index;
        std::string first;
        std::string last;
        std::string nickname;
        std::string number;
        std::string secret;
        Contact();
        ~Contact();
};

#endif