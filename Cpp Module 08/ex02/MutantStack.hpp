#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#include "MutantStack.tpp"

#endif

/*이 클래스는 표준 라이브러리의 std::stack을 확장하여 반복자(iterator) 기능을 추가합니다.

템플릿 클래스 정의:

MutantStack 클래스는 template <typename T>를 사용하여 템플릿 클래스로 정의되었습니다. 
여기서 T는 스택에 저장될 데이터 타입을 나타냅니다.
상속:MutantStack이 std::stack을 상속
반복자 타입 정의:
iterator와 const_iterator 타입은 std::stack의 내부 컨테이너(여기서는 deque)의 반복자 타입입니다. 
이를 통해 MutantStack의 요소에 대한 반복자 접근이 가능해집니다.
반복자 메서드:
begin()과 end() 메서드는 MutantStack의 시작과 끝을 가리키는 반복자를 반환합니다. 
const 오버로드 버전은 읽기 전용 접근을 제공합니다.*/

/*사용 방법:
main.cpp에서 MutantStack의 인스턴스를 생성하고, push 메서드로 요소를 추가합니다.
top과 pop 메서드로 스택의 최상위 요소에 접근하거나 제거합니다.
begin과 end를 사용하여 MutantStack의 요소를 반복하고 출력합니다.
이 구현을 통해 std::stack의 기능을 유지하면서 반복자를 통한 접근이 가능한 컨테이너를 만들 수 있습니다. 
이는 std::stack이 기본적으로 제공하지 않는 기능으로, MutantStack을 통해 새로운 기능성을 추가한 것입니다.*/

/*Exercise 02 요구사항:

std::stack을 확장하여 반복 가능하게 만들기:
MutantStack 클래스는 std::stack을 상속받아 구현되었습니다. 
이를 통해 std::stack의 모든 기능을 유지하면서 추가적인 기능을 제공할 수 있습니다.
MutantStack에서는 std::stack의 내부 컨테이너에 접근하여 반복자(iterator)를 제공합니다. 
이는 begin()과 end() 메서드를 통해 구현됩니다.

모든 멤버 함수와 추가적인 기능 제공:
MutantStack은 std::stack의 모든 멤버 함수(예: push, pop, top, size 등)를 상속받아 제공합니다.
추가적으로 begin과 end 메서드를 통해 반복자 기능을 제공합니다. 
이 기능은 std::stack에는 존재하지 않는 MutantStack의 특징입니다.

main.cpp 테스트 코드:
MutantStack 인스턴스 생성 및 기본 스택 작업 수행:
MutantStack<int> 타입의 mstack 인스턴스를 생성합니다.
push, pop, top, size 등의 std::stack의 기본적인 기능을 사용하여 
스택에 요소를 추가하고, 가장 상단의 요소를 검사하며, 스택의 크기를 확인합니다.
반복자를 사용한 요소 순회 및 출력:

begin과 end 메서드를 사용하여 MutantStack의 반복자를 초기화하고, 
이를 사용하여 스택의 모든 요소를 순회하며 출력합니다.
이는 std::stack에서 제공하지 않는 기능으로, 
MutantStack의 확장된 기능성을 보여줍니다.
이 구현은 문제에서 요구한 대로 std::stack의 기능을 확장하고, 
추가적으로 반복자를 통한 순회 기능을 제공합니다. 
main.cpp의 테스트 코드는 이러한 기능들이 실제로 어떻게 동작하는지를 보여줍니다. 
이를 통해 사용자는 MutantStack 클래스가 기존 std::stack의 기능을 어떻게 유지하고 확장했는지 이해할 수 있습니다.*/