#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData;
    originalData.intValue = 42;
    originalData.doubleValue = 3.14;
    originalData.charValue = 'A';

    // 직렬화
    uintptr_t rawData = Serializer::serialize(&originalData);

    // 역직렬화
    Data* deserializedData = Serializer::deserialize(rawData);

    // 결과 테스트
    std::cout << "Original Data: " << originalData.intValue << ", " << originalData.doubleValue << ", " << originalData.charValue << std::endl;
    std::cout << "Deserialized Data: " << deserializedData->intValue << ", " << deserializedData->doubleValue << ", " << deserializedData->charValue << std::endl;

    return 0;
}
