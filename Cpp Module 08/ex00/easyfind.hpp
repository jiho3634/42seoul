#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Not found";
    }
};

template <typename T>
void easyfind(T& container, int value) {
    try {
        //typename 키워드: T::iterator가 타입임을 컴파일러에게 알려줍니다.
        //C++에서는 템플릿 매개변수 T가 컴파일 시점까지 구체적인 타입이 결정되지 않기 때문에, 
        //컴파일러는 T::iterator가 타입인지, 아니면 정적 멤버 변수나 다른 멤버의 이름인지를 알 수 없습니다. 
        //typename을 사용하여 이를 타입임을 명시해야 합니다.
        //T::iterator -> std::vector<int>::iterator
        
        //std::find C++ 표준 라이브러리의 알고리즘 헤더(<algorithm>)에 정의된 일반 함수입니다.
        //container.begin()에서 시작하여 container.end()까지 이터레이트하면서 각 요소를 value와 비교합니다. 
        //일치하는 첫 번째 요소를 찾으면 해당 요소를 가리키는 반복자를 반환합니다. 
        //만약 일치하는 요소가 없으면 container.end()를 반환합니다.
        
        //begin() 멤버 함수는 컨테이너의 첫 번째 요소를 가리키는 반복자를 제공합니다.
        
        //end(): 이것은 container의 끝을 나타내는 반복자를 반환합니다. 
        //이 반복자는 실제로 컨테이너의 마지막 요소 다음을 가리키는 '파스트-더-엔드'(past-the-end) 반복자입니다.
        // 즉, 컨테이너의 마지막 요소를 포함하지 않고, 그 뒤에 있는 "가상의" 위치를 가리킵니다.
        typename T::iterator it = std::find(container.begin(), container.end(), value);
        if (it == container.end()) {
            throw NotFoundException();
        } else {
            // C++ 표준 라이브러리의 <iterator> 헤더에 정의된 함수로, 두 반복자 사이의 거리를 계산합니다. 
            //이 함수는 시작 반복자(container.begin())와 목표 반복자(it)를 매개변수로 받아,
            //시작 반복자로부터 목표 반복자까지 몇 개의 요소가 있는지를 나타내는 거리를 반환합니다.
            std::cout << "index: " << std::distance(container.begin(), it) << std::endl;
        }
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
}

#endif
