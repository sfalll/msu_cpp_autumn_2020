#include "format.hpp"
#include "matrix.hpp"
#include <iostream>
#include <cassert>

void PositiveTest(){
    std::string text = format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");
    text = format("{001} + {0} + {2} = {3}", 1, 2, 3, 6);
    assert(text == "2 + 1 + 3 = 6");
    text = format("{0}+ {1}= {2}", Matrix(1, 1, 2), Matrix(1, 1, 1), Matrix(1, 1, 3)); // матрица взята из 3 дз
    assert(text == "2 + 1 = 3 ");
}

void WrongValueTest(){
    bool flag = false;
    try{
        std::string text = format("{1} + {2} + {a}", 1, 2, 3);
    }
    catch(const ValueError &e){
        flag = true;
    }
    assert(flag);
    flag = false;
    try{
        std::string text = format("{1.2} + {2}", 3, 4);
    }
    catch(const ValueError &e){
        flag = true;
    }
    assert(flag);
    flag = false;
    try{
        std::string text = format("{0}, {1}", 1);
    }
    catch(const ValueError &e){
        flag = true;
    }
    assert(flag);
    flag = false;
    try{
        std::string text = format("{}, {}", 1);
    }
    catch(const ValueError &e){
        flag = true;
    }
    assert(flag);
}

void BadBracketsTest(){
    bool flag = false;
    try{
        std::string text = format("{1} + {{2}}", 1, 2, 3);
    }
    catch(const BracketsError &e){
        flag = true;
    }
    assert(flag);
    flag = false;
    try{
        std::string text = format("{1} + {2}}", 1, 2, 3);
    }
    catch(const BracketsError &e){
        flag = true;
    }
    assert(flag);
    flag = false;
    try{
        std::string text = format("{{1} + {2}", 1, 2, 3);
    }
    catch(const BracketsError &e){
        flag = true;
    }
    assert(flag);
}

int main(){
    PositiveTest();
    WrongValueTest();
    BadBracketsTest();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}