#include "parser.hpp"
#include <cassert>

// для чисел будем считать сумму цифр
std::string CustomDigitCallback(const std::string &str){
    size_t ans = 0;
    for(auto c: str)
        ans += static_cast<size_t>(c - '0');
    std::cout << ans << std::endl;
    return std::to_string(ans);
}

// для строк будем заменять мальнькие буквы на большие
std::string CustomStringCallback(const std::string &str){
    std::string ans;
    for(auto c: str){
        if(isdigit(c))
            ans += c;
        else
            ans += toupper(c);
    }
    std::cout << ans << std::endl;
    return ans;
}

void ParsingTest(){
    Parser parser;
    std::string str = "123 abc abc123 \t ABC1 \n 123a";
    std::vector<std::string> ans;
    std::vector<std::string> rightAns = {"123", "abc", "abc123", "ABC1", "123a"};
    ans = parser.Parse(str);
    assert(ans == rightAns);
}

void SetTokenCallbackTest(){
    Parser parser;
    parser.SetDigitCallback(CustomDigitCallback);
    std::string str = "123 abc abc123 \t ABC1 \n 112233";
    std::vector<std::string> ans;
    std::vector<std::string> rightAns = {"6", "abc", "abc123", "ABC1", "12"};
    ans = parser.Parse(str);
    assert(ans == rightAns);
    parser.SetStringCallback(CustomStringCallback);
    rightAns = {"6", "ABC", "ABC123", "ABC1", "12"};
    ans = parser.Parse(str);
    assert(ans == rightAns);
}

void SetInfoCallback(){
    Parser parser;
    std::vector<std::string> ans;
    std::string str = "123 abc abc123 \t ABC1 \n 112233";
    bool startFlag = false, finishFlag = false;
    parser.SetFinishCallback([&finishFlag](){
        finishFlag = true; 
        std::cout << "Parsing finished" << std::endl << std::string(25, '-') << std::endl;
        });
    parser.SetStartCallback([&startFlag](){
        startFlag = true; 
        std::cout << "Start parsing" << std::endl;
        });
    ans = parser.Parse(str);
    assert(startFlag);
    assert(finishFlag);
}

int main(){
    ParsingTest();
    SetTokenCallbackTest();
    SetInfoCallback();
    std::cout << "All test passed!" << std::endl;
    return 0;
}