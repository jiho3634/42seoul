#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
public:
    Zombie(std::string name);
    void announce() const;
    void setName(std::string name);
	Zombie();

private:
    std::string _name;
};

#endif
