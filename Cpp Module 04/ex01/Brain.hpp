#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain& src);
    Brain& operator=(const Brain& src);
    ~Brain();

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;

private:
    std::string _ideas[100];
};

#endif
