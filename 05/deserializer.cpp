#include "deserializer.hpp"

Deserializer::Deserializer(std::istream &in) : in_(in){
}

Error Deserializer::Process(uint64_t& value){
    uint64_t buf;
    std::string str;

    in_>> str;
    try{
        buf = std::stoull(str);
    }
    catch(const std::invalid_argument &e){
        return Error::CorruptedArchive;
    }

    value = buf;
    return Error::NoError;
}


Error Deserializer::Process(bool &value){
    std::string str;

    in_ >> str;

    if(str == "true")
        value = true;
    else
        if(str == "false")
            value = false;
    else
        return Error::CorruptedArchive;

    return Error::NoError;
}