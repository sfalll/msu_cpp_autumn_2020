#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

class Allocator{
private:
    size_t maxSize_ = 0, offset_ = 0;
    char* start_ = nullptr;
public:
    ~Allocator();
    void MakeAllocator(size_t maxSize);
    char* Alloc(size_t size);
    void Reset();
};

#endif