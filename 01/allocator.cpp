#include <iostream>
#include "allocator.hpp"


void Allocator::MakeAllocator(size_t maxSize){
    if(start_ == nullptr){
        maxSize_ = maxSize;
        start_ = new char[maxSize];
        if(start_ == nullptr){
            std::cout << "Can't alloc memory" << std::endl;
            exit(-1);
        }
    }
    else{
        delete[] start_;
        start_ = nullptr;
        maxSize_ = maxSize;
        offset_ = 0;
        start_ = new char[maxSize];
        if(start_ == nullptr){
            std::cout << "Can't alloc memory" << std::endl;
            exit(-1);
        }
    }
}

char* Allocator::Alloc(size_t size){
    if(size == 0 || offset_ + size > maxSize_){
        return nullptr;
    }
    char* res = start_ + offset_;
    offset_ += size;
    return res; 
}

void Allocator::Reset(){
    offset_ = 0;
}

Allocator::~Allocator(){
    delete[] start_;
}