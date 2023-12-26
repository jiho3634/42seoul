#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer {
private:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif

/*
직렬화(Serialization)와 역직렬화(Deserialization)는 
데이터 구조나 객체 상태를 다른 포맷으로 변환하는 과정을 말합니다.
이는 데이터를 저장하거나, 네트워크를 통해 전송할 때 사용됩니다.

직렬화 (Serialization):

직렬화는 복잡한 데이터 구조(예: 객체, 트리, 연결 리스트)를 
연속된 데이터 형식(예: 문자열, 바이트 스트림)으로 변환하는 과정.
이 과정을 통해 데이터를 파일 시스템에 저장하거나 네트워크를 통해 다른 시스템으로 전송할 수 있습니다.
직렬화의 예로는 JSON, XML 형식으로 객체를 변환하거나, 
Java의 Serializable 인터페이스, Python의 pickle 모듈 등이 있습니다.
역직렬화 (Deserialization):

역직렬화는 직렬화된 데이터를 원래의 데이터 구조나 객체 상태로 되돌리는 과정입니다.
파일 시스템에서 데이터를 읽거나 네트워크를 통해 받은 데이터를 원래의 형태로 복원할 때 사용됩니다.
역직렬화는 직렬화된 데이터를 정확히 이해하고, 원래의 객체 타입과 구조에 맞게 변환해야 하므로, 
직렬화 과정에서 사용된 형식과 방법을 알고 있어야 합니다.
직렬화와 역직렬화는 데이터 교환, 원격 프로시저 호출(RPC), 분산 컴퓨팅 등 다양한 분야에서 중요한 역할을 합니다. 
이 과정을 통해 시스템 간의 호환성을 유지하면서 데이터를 안전하게 전송하고 저장할 수 있습니다. 
그러나 직렬화 과정은 데이터의 구조를 변경하기 때문에, 보안과 데이터 무결성을 유지하기 위한 주의가 필요합니다. 
역직렬화 과정에서는 데이터의 소스와 형식을 신중하게 검증하여 보안 취약점을 방지해야 합니다.
*/
