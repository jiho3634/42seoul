#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>

class ASpell; // 전방 선언

class ATarget {
protected:
    std::string type;

public:
    ATarget(const std::string& type);
    virtual ~ATarget();

    const std::string& getType() const;

    virtual ATarget* clone() const = 0;

    void getHitBySpell(const ASpell& spell) const;
};

#endif
