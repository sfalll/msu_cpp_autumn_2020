#include "matrix.hpp"
#include <cassert>

void GetColRowTest(){
    Matrix m1(10, 20);
    assert(m1.GetCols() == 20);
    assert(m1.GetRows() == 10);
    Matrix m2(20, 10);
    assert(m2.GetCols() == 10);
    assert(m2.GetRows() == 20); 
}

void GetElemTest(){
    Matrix m(10, 20, 1);
    assert(m[1][1] == 1);
    m[1][1] = 22;
    m[3][4] = 65;
    assert(m[1][1] == 22);
    assert(m[3][4] == 65);
    bool flag = false;
    try{
        m[10][9];
    }
    catch(const std::out_of_range &e){
        flag = true;
    }
    assert(flag);
}

void MultTest(){
    Matrix m(2, 2);
    for(size_t i = 0; i < m.GetRows(); i++)
        for(size_t j = 0; j < m.GetCols(); j++)
            m[i][j] = i * m.GetCols() + j + 1;
    m *= 4;
    assert(m[0][0] == 4);
    assert(m[1][0] == 12);
    assert(m[0][1] == 8);
    assert(m[1][1] == 16);
}

void EqTest(){
    Matrix m1(10, 20, 5), m2(10, 20, 4), m3(10, 20, 5), m4(11, 20, 5), m5(10, 21, 5);
    assert(m1 != m2);
    assert(m1 == m3);
    assert(m1 != m4);
    assert(m1 != m5);
}

void AddTest(){
    Matrix m1(10, 20, 5), m2(10, 20, 2), m3(10, 20, 3), m4(20, 10);
    assert(m2 + m3 == m1);
    assert(m1 + m2 != m3);
    bool flag = false;
    try{
        m4 + m1;
    }
    catch(const std::out_of_range &e){
        flag = true;
    }
    assert(flag);
}

void PrintTest(){
    Matrix m(5, 10);
    std::cout << "Start print test: " << std::endl;
    for(size_t i = 0; i < m.GetRows(); i++)
        for(size_t j = 0; j < m.GetCols(); j++)
            m[i][j] = i * m.GetCols() + j + 1;
    std::cout << m << std::endl;
}

int main(){
    GetColRowTest();
    GetElemTest();
    MultTest();
    EqTest();
    AddTest();
    PrintTest();
    std::cout << "All test passed!" << std::endl;
    return 0;
}