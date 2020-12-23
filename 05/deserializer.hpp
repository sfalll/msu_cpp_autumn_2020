#ifndef DESERIALIZER_HPP
#define DESERIALIZER_HPP

#include "serializer.hpp"
#include <string>

class Deserializer{
private:
    static constexpr char Separator = ' ';
    std::istream &in_;
    Error Process(uint64_t &value);
    Error Process(bool& value);

    template<class T, class... ArgsT>
    Error Process(T& arg, ArgsT& ...args);
public:
    explicit Deserializer(std::istream &in);

    template<class T>
    Error Load(T& object);

    template <class... ArgsT>
    Error operator()(ArgsT&... args);
};


template<class T>
Error Deserializer::Load(T& object){
    return object.deserialize(*this);
}

template <class... ArgsT>
Error Deserializer::operator()(ArgsT&... args){
    return Process(args...);
}

template<class T, class... ArgsT>
Error Deserializer::Process(T& arg, ArgsT& ...args){
    if(Process(arg) != Error::NoError)
        return Error::CorruptedArchive;
    if(Process(args...) != Error::NoError)
        return Error::CorruptedArchive;
    return Error::NoError;
}

#endif