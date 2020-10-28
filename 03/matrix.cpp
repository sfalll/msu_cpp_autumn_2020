#include "matrix.hpp"

Matrix::Matrix(size_t rows, size_t cols, int val) : rows_(rows), cols_(cols){
    if(rows <= 0 || cols <= 0)
        throw std::out_of_range("Incorrect size");
    data_ = new int[rows * cols];
    for(size_t i = 0; i < rows_; i++)
        for(size_t j = 0; j < cols_; j++)
            data_[i * cols_ + j] = val;
}

Matrix::~Matrix(){
    delete[] data_;
}

size_t Matrix::GetRows() const{
    return rows_;
}

size_t Matrix::GetCols() const{
    return cols_;
}

Matrix& Matrix::operator*=(int val){
    for(size_t i = 0; i < rows_; i++)
        for(size_t j = 0; j < cols_; j++)
            data_[i * cols_ + j] *= val;
    return *this;
}

bool Matrix::operator==(const Matrix &other) const{
    if(rows_ != other.rows_ || cols_ != other.cols_)
        return false;
    for(size_t i = 0; i < rows_; i++)
        for(size_t j = 0; j < cols_; j++)
            if(data_[i * cols_ + j] != other.data_[i * cols_ + j])
                return false;
    return true;
}

bool Matrix::operator!=(const Matrix &other) const{
    return !(*this == other);
}

Matrix Matrix::operator+(const Matrix &other) const{
    if(rows_ != other.rows_ || cols_ != other.cols_)
        throw std::out_of_range("Different sizes");
    Matrix res(rows_, cols_);
    for(size_t i = 0; i < rows_; i++)
        for(size_t j = 0; j < cols_; j++)
            res.data_[i * cols_ + j] = data_[i * cols_ + j] + other.data_[i* cols_ + j];
    return res;
}

Proxy Matrix::operator[](size_t num){
    if(num >= rows_)
        throw std::out_of_range("Row index out of range");
    return Proxy(&data_[num * cols_], cols_);
}

const Proxy Matrix::operator[](size_t num) const{
    if(num >= rows_)
        throw std::out_of_range("Row index out of range");
    return Proxy(&data_[num * cols_], cols_);
}

Proxy::Proxy(int *data, size_t cols) : data_(data), cols_(cols){}

int& Proxy::operator[](size_t num){
    if(num >= cols_)
        throw std::out_of_range("Column index out of range");
    return data_[num];
}

const int& Proxy::operator[](size_t num) const{
    if(num >= cols_)
        throw std::out_of_range("Column index out of range");
    return data_[num];
}

std::ostream& operator<<(std::ostream& out, const Matrix& m){
    for(size_t i = 0; i < m.rows_; i++){
        for(size_t j = 0; j < m.cols_; j++)
            out << m.data_[i * m.cols_ + j] << ' ';
        out << std::endl;
    }
    return out;
}