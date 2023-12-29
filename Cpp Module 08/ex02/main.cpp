#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    return 0;
}

/*std::stack으로의 변환:
std::stack<int> s(mstack);
MutantStack 객체를 std::stack 객체로 변환합니다. 
이는 MutantStack이 std::stack의 모든 기능을 상속받았기 때문에 가능합니다.
main.cpp 파일은 MutantStack 클래스가 std::stack의 기능을 어떻게 확장하는지 보여주는 훌륭한 예입니다. 
특히, 반복자를 사용한 순회는 std::stack에는 없는 MutantStack의 독특한 기능입니다. 
이를 통해 사용자는 MutantStack의 모든 요소에 쉽게 접근할 수 있습니다.*/
