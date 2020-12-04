#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <cstddef>
#include <string>
#include <iostream>

using uc = unsigned char;

class BigInt{
private:
    const int BASE = 10;
    uc* num_;
    bool sign_;
    size_t size_;
    bool AbsGreater(const BigInt &other) const;
    void DeleteZeros();
    void MakeZeros(size_t size);
public:
    BigInt();
    BigInt(int val);
    BigInt(const std::string& str);
    ~BigInt();
    BigInt(const BigInt& other);
    BigInt(BigInt&& other);
    BigInt& operator=(const BigInt& other);
    BigInt& operator=(BigInt &&other);
    bool operator < (const BigInt &other) const;
    bool operator <= (const BigInt &other) const;
    bool operator > (const BigInt &other) const;
    bool operator >= (const BigInt &other) const;
    bool operator == (const BigInt &other) const;
    bool operator != (const BigInt &other) const;
    bool operator < (int other) const;
    bool operator <= (int other) const;
    bool operator > (int other) const;
    bool operator >= (int other) const;
    bool operator == (int other) const;
    bool operator != (int other) const;
    BigInt operator - () const;
    BigInt operator + (const BigInt &other) const;
    BigInt operator - (const BigInt &other) const;
    BigInt operator * (const BigInt &other) const;
    BigInt operator + (int other) const;
    BigInt operator - (int other) const;
    BigInt operator * (int other) const;
    BigInt& operator += (const BigInt &other);
    BigInt& operator -= (const BigInt &other);
    BigInt& operator *= (const BigInt &other);
    BigInt& operator += (int other);
    BigInt& operator -= (int other);
    BigInt& operator *= (int other);
    friend std::ostream& operator<<(std::ostream& out, const BigInt& n);
};

#endif