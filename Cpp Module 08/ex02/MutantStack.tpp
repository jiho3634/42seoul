template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

// begin 메서드
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

// end 메서드
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

// const begin 메서드
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

// const end 메서드
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}

/*MutantStack.tpp
반복자 메서드 구현:
begin()과 end() 메서드는 this->c를 사용합니다. 
여기서 c는 std::stack의 내부 컨테이너를 나타내며, std::stack의 protected 멤버입니다. 
이를 통해 내부 컨테이너의 시작과 끝 반복자를 얻을 수 있습니다.*/

