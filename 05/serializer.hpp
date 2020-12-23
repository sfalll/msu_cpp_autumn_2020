#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

enum class Error{
    NoError,
    CorruptedArchive
};

class Serializer{
private:
    std::ostream &out_;
    static constexpr char separator = ' ';
    void Process(uint64_t value);
    void Process(bool value);

    template <class T, class... ArgsT>
    Error Process(T arg, ArgsT... args);
public:
    explicit Serializer(std::ostream& out);
    ~Serializer() = default;
    
    template<class T>
    Error Save(T& object);

    template<class... ArgsT>
    Error operator()(ArgsT... args);
};


template <class T, class... ArgsT>
Error Serializer::Process(T arg, ArgsT... args){
    Process(arg);
    Process(args...);
    return Error::NoError;
}

template<class... ArgsT>
Error Serializer::operator()(ArgsT... args){
    return Process(args...);
}

template<class T>
Error Serializer::Save(T& object){
    return object.serialize(*this);
}

#endif