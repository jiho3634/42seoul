#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>//std::srand std::rand
#include <ctime>//time(NULL)

// 객체 생성 함수
Base* generate() {
    switch (rand() % 3) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

// 타입 식별 함수
void identify(Base* p) {
    //dynamic_cast로 다운캐스팅에 실패하면, NULL을 반환한다. 
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (const std::bad_cast&) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (const std::bad_cast&) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // 난수 초기화

    // for (int i = 0; i < 10; ++i) {
        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
        // std::cout << std::endl;
    // }

    return 0;
}
