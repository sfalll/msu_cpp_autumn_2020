#include "deserializer.hpp"
#include <cassert>
#include <sstream>

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a, b, c);
    }
};

struct AnotherData{
    uint64_t b;
    bool a;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a, b);
    }
};


void BasicTest(){
    Data d1 {110, true, 200};
    Data d2 {0, false, 110};

    std::stringstream ss;

    Serializer serializer(ss);
    Error err1 = serializer.Save(d1);

    Deserializer deserializer(ss);
    Error err2 = deserializer.Load(d2);

    assert(err1 == Error::NoError);
    assert(err2 == Error::NoError);

    assert(d1.a == d2.a);
    assert(d1.b == d2.b);
    assert (d1.c == d2.c);
}

void BadTest(){
    AnotherData d1 {110, true};
    Data d2 {0, false, 0};

    std::stringstream ss;

    Serializer serializer(ss);
    Error err1 = serializer.Save(d1);

    Deserializer deserializer(ss);
    Error err2 = deserializer.Load(d2);

    assert(err1 == Error::NoError);
    assert(err2 == Error::CorruptedArchive);

    ss.clear();

    err1 = serializer.Save(d2);

    err2 = deserializer.Load(d1);

    assert(err1 == Error::NoError);
    assert(err2 == Error::CorruptedArchive);
}

void ManyStructuresTest(){
    AnotherData d1 {110, true};
    Data d2 {0, false, 0};
    AnotherData d3{0, false};
    Data d4 {100, true, 200};

    std::stringstream ss;

    Serializer serializer(ss);
    Error err1 = serializer.Save(d1);
    Error err3 = serializer.Save(d2);

    Deserializer deserializer(ss);
    Error err2 = deserializer.Load(d3);
    Error err4 = deserializer.Load(d4);

    assert(err1 == Error::NoError);
    assert(err2 == Error::NoError);
    assert(err3 == Error::NoError);
    assert(err4 == Error::NoError);

    assert(d1.a == d3.a);
    assert(d1.b == d3.b);

    assert(d2.a == d4.a);
    assert(d2.b == d4.b);
    assert(d2.c == d4.c);
}

int main(){
    BasicTest();
    BadTest();
    ManyStructuresTest();
    std::cout << "Alll tests passed!" << std::endl;
    return 0;
}