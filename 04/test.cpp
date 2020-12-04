#include "big.hpp"
#include <cassert>

// в этом тесте также проверяется, что конструкторы от строки и от int работают правильно
void LessTest(){
    assert(BigInt(100) < BigInt(200));
    assert(BigInt(100) <= BigInt(200));
    assert(BigInt(100) <= BigInt(100));

    assert(BigInt(100) < BigInt("200"));
    assert(BigInt(100) <= BigInt("200"));
    assert(BigInt(100) <= BigInt("100"));

    assert(BigInt(100) < 200);
    assert(BigInt(100) <= 200);
    assert(BigInt(100) <= 100);

    assert(BigInt(-200) < BigInt(-100));
    assert(BigInt(-200) <= BigInt(-100));
    assert(BigInt(-200) <= BigInt(-200));

    assert(BigInt(-200) < BigInt("-100"));
    assert(BigInt(-200) <= BigInt("-100"));
    assert(BigInt(-200) <= BigInt("-200"));

    assert(BigInt(-200) < -100);
    assert(BigInt(-200) <= -100);
    assert(BigInt(-200) <= -200);
}

void GreaterTest(){
    assert(BigInt(200) > 100);
    assert(BigInt(200) >= 100);
    assert(BigInt(200) >= 200);

    assert(BigInt(-100) > -200);
    assert(BigInt(-100) >= -200);
    assert(BigInt(-100) >= -100);
}

void EqTest(){
    assert(BigInt(100) == 100);
    assert(BigInt(-123456) == -123456);
    assert(BigInt(654321) != -654321);
    assert(BigInt(-654321) != 654321);
}

void AddTest(){
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    // std::cout << a + c << std::endl;
    assert(a + b == BigInt("23333333231"));
    assert(a + c == 0);
    assert(c + a == 0);
    assert(c + d == BigInt("-23333333231"));

    assert(a + 1 == BigInt("12345678911"));
    assert(b + (-1) == BigInt("10987654320"));
    assert(d + 1 == BigInt("-10987654320"));
    assert(c + (-1) == BigInt("-12345678911"));

    a += c;
    assert(a == 0);
}

void SubTest(){
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    // std::cout << b - a << std::endl;
    assert(a - b == BigInt("1358024589"));
    assert(b - a == BigInt("-1358024589"));
    assert(a - a == 0);
    assert(c - c == 0);

    assert(a - (-1) == BigInt("12345678911"));
    assert(b - 1 == BigInt("10987654320"));
    assert(d - (-1) == BigInt("-10987654320"));
    assert(c - 1 == BigInt("-12345678911"));

    a -= b;
    assert(a == BigInt("1358024589"));
}

void MultTest(){
    BigInt a("12345678910"), b("10987654321"), c("-12345678910"), d("-10987654321");
    // std::cout << b * c << std::endl;
    assert(a * b == BigInt("135650052221140070110"));
    assert(c * d == BigInt("135650052221140070110"));
    assert(b * c == BigInt("-135650052221140070110"));
    assert(a * d == BigInt("-135650052221140070110"));

    assert(a * 0 == 0);
    assert(a * (-1) == BigInt("-12345678910"));

    a *= b;
    b *= 0;
    assert(a == BigInt("135650052221140070110"));
    assert(b == 0);
}

void MinusTest(){
    BigInt a = 10, b = -123;
    assert(-a == -10);
    assert(-b == 123);
}

void OperatorTest(){
    BigInt a(100), b, c;
    b = a;
    assert(b == 100);
    c = std::move(a);
    assert(c == 100);
    assert(a != 100);
}

void PrintTest(){
    BigInt a("12345678910"), b("-10987654321"), c("00005"), d("-0000");
    std::cout << "Print test" << std::endl;
    std::cout << "12345678910 = " << a << std::endl;
    std::cout << "-10987654321 = " << b << std::endl;
    std::cout << "5 = " << c << std::endl;
    std::cout << "0 = " << d << std::endl;
}

int main(){
    LessTest();
    GreaterTest();
    EqTest();
    AddTest();
    SubTest();
    MultTest();
    MinusTest();
    OperatorTest();
    PrintTest();
    std::cout << "All test passed!" << std::endl;
    return 0;
}