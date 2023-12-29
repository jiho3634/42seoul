#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> vec;
    for (size_t i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }
    for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    easyfind(vec, 3);
    easyfind(vec, 6); // 예외 발생

    return 0;
}
