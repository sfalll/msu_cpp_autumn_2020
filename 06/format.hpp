#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <sstream>
#include <cstddef>
#include <string>
#include <exception>
#include <cctype>


class ValueError: public std::exception{
public:
    const char* what() const noexcept override{
        return "Wrong value in {}";
    }
};

class BracketsError: public std::exception{
public:
    const char* what() const noexcept override{
        return "Wrong brackets usage";
    }
};

template <class T>
void parse(std::ostream &out, size_t num, const T& arg){
    if(num == 0)
        out << arg;
    else
        throw ValueError();
}

template <class T, class... Args>
void parse(std::ostream &out, size_t num, const T &arg, const Args&... args){
    if(num == 0)
        out << arg;
    else
        parse(out, num - 1, args...);
}


template <class... Args>
std::string format(const std::string &s, const Args& ... args){
    std::ostringstream ss;
    bool flag = false;
    bool is_num = false;
    size_t buf = 0;
    for(auto c: s){
        if(c == '{'){
            if(flag)
                throw BracketsError();
            flag = true;
            continue;
        }
        if(c == '}'){
            if(!flag)
                throw BracketsError();
            if(!is_num)
                throw ValueError();
            flag = false;
            parse(ss, buf, args...);
            buf = 0;
            is_num = false;
            continue;
        }
        if(flag){
            if(!std::isdigit(c))
                throw ValueError();
            buf = buf * 10 + static_cast<size_t>(c - '0');
            is_num = true;
            continue;  
        }
        ss << c;
    }
    if(flag)
        throw BracketsError();
    return ss.str();
}

#endif