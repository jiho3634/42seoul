#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : count(0) {}

Span::Span(unsigned int N) : count(N) {}

Span::Span(const Span& other) : numbers(other.numbers), count(other.count) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->numbers = other.numbers;
        this->count = other.count;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() < count) {
        numbers.push_back(number);
    } else {
        throw std::exception();
    }
}
//std::lower_bound(numbers.begin(), numbers.end(), number)는 벡터에서 삽입할 위치를 찾습니다. 
//벡터가 이미 정렬되어 있다고 가정하므로, 이 함수는 number보다 크거나 같은 첫 번째 요소의 반복자를 반환합니다.
//insertPos = std::lower_bound(numbers.begin(), numbers.end(), number);
//numbers.insert(insertPos, number)는 찾은 위치 insertPos에 number를 삽입합니다. 

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::exception();
    }

    std::vector<int> temp = numbers;
    //std::sortd는 C++ 표준 템플릿 라이브러리(STL)의 <algorithm> 헤더 파일에 정의된 함수입니다.
    // 이 함수는 주어진 범위 내의 요소들을 정렬하는 데 사용됩니다.
    std::sort(temp.begin(), temp.end());

    int min = std::numeric_limits<int>::max();
    for (size_t i = 1; i < temp.size(); i++) {
        int span = temp[i] - temp[i - 1];
        if (span < min) {
            min = span;
        }
    }

    return min;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::exception();
    }

    int minNum = *std::min_element(numbers.begin(), numbers.end());
    int maxNum = *std::max_element(numbers.begin(), numbers.end());

    return maxNum - minNum;
}
