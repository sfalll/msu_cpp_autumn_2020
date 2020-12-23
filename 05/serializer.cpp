#include "serializer.hpp"

Serializer::Serializer(std::ostream& out): out_(out){
}

void Serializer::Process(uint64_t value){
    out_ << value;
    out_ << separator;
}

void Serializer::Process(bool value){
    if(value)
        out_ << "true";
    else
        out_ << "false";
    out_ << separator;
}