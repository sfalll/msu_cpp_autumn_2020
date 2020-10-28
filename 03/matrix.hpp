#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <iostream>

class Proxy{
private:
    int *data_;
    size_t cols_;
public:
    Proxy(int *data, size_t cols);
    int& operator[](size_t num);
    const int& operator[](size_t num) const;
};

class Matrix{
private:
    size_t rows_;
    size_t cols_;
    int *data_;

public:
    Matrix(size_t rows, size_t cols, int val=0);
    ~Matrix();
    size_t GetCols() const;
    size_t GetRows() const;
    friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
    Matrix& operator*=(int val);
    bool operator==(const Matrix &other) const;
    bool operator!=(const Matrix &other) const;
    Matrix operator+(const Matrix &other) const;
    Proxy operator[](size_t num);
    const Proxy operator[](size_t num) const;
};

#endif