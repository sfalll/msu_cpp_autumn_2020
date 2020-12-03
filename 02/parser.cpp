#include "parser.hpp"

Parser::Parser(){
    StartCallback_ = [](){
        std::cout << "Start parsing" << std::endl;
        };
    FinishCallback_ = [](){
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        };
    DigitCallback_ = [](const std::string & s){
        std::cout << s << std::endl; return s;
        };
    StringCallback_ = DigitCallback_;
}

void Parser::SetDigitCallback(TokenCallback call){
    DigitCallback_ = call;
}

void Parser::SetStringCallback(TokenCallback call){
    StringCallback_ = call;
}

void Parser::SetStartCallback(InfoCallback call){
    StartCallback_ = call;
}

void Parser::SetFinishCallback(InfoCallback call){
    FinishCallback_ = call;
}

// результат вызова callback-a помещаю в вектор, для более простого тестирования

std::vector<std::string> Parser::Parse(const std::string & s){
    StartCallback_();
    std::vector<std::string> res;
    std::string token;
    bool isDigit = true;
    for(auto c: s){
        if(!isspace(c)){
            token += c;
            if(!isdigit(c))
                isDigit = false;
        }
        else{
            if(!token.empty()){
                if(isDigit)
                    res.push_back(DigitCallback_(token));
                else
                    res.push_back(StringCallback_(token));
                token.clear();
                isDigit = true;
            }
        }
    }
    if(!token.empty()){
        if(isDigit)
            res.push_back(DigitCallback_(token));
        else
            res.push_back(StringCallback_(token));
    }
    FinishCallback_();
    return res;
}