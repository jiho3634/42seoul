#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer&) {
}

Serializer& Serializer::operator=(const Serializer&) {
    return *this;
}

Serializer::~Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

/*
reinterpret_cast는 C++의 강력하고 유연한 캐스팅 연산자 중 하나로, 
한 포인터 타입을 다른 포인터 타입으로, 또는 포인터를 충분한 크기를 갖는 정수 타입으로 변환하는 데 사용됩니다. 
이 캐스팅은 비트 단위로 수행되며, 실제 메모리 내용은 변경되지 않습니다.

reinterpret_cast의 주요 사용 사례는 다음과 같습니다:

포인터 타입 간 변환: 서로 다른 타입의 포인터 간에 변환을 수행할 때 사용합니다. 
예를 들어, char*를 int*로 변환하거나 그 반대의 경우 등이 있습니다. 
이런 변환은 기본적으로 메모리의 비트 패턴을 해석하는 방식만을 변경합니다.

포인터와 정수 타입 간 변환: 포인터를 정수로 변환하거나, 반대로 정수를 포인터로 변환할 때 사용합니다. 
이는 주소 값을 저장하거나, 특정 메모리 주소로 직접 접근하는 데 사용될 수 있습니다.

reinterpret_cast는 매우 낮은 수준의 캐스팅을 수행하기 때문에 사용 시 주의가 필요합니다. 
변환된 포인터를 사용해 역참조하는 경우, 원래 타입과 호환되지 않는 타입으로 역참조하면 실행 시 오류가 발생할 수 있습니다.
이는 reinterpret_cast가 타입 시스템의 안전성을 보장하지 않기 때문입니다.
*/