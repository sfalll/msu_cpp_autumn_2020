#include <iostream>
#include <cassert>
#include "allocator.hpp"

void ManyAllocTest(){
    Allocator allocator;
    allocator.makeAllocator(20);
    assert(allocator.alloc(10) != nullptr);
    assert(allocator.alloc(8) != nullptr);
    assert(allocator.alloc(0) == nullptr);
    assert(allocator.alloc(1) != nullptr);
    assert(allocator.alloc(2) == nullptr);
    assert(allocator.alloc(1) != nullptr);
    assert(allocator.alloc(1) == nullptr);
}

void ResetTest(){
    Allocator allocator;
    allocator.makeAllocator(20);
    assert(allocator.alloc(10) != nullptr);
    assert(allocator.alloc(11) == nullptr);
    allocator.reset();
    assert(allocator.alloc(11) != nullptr);
}

void ReMakeAllocatorTest(){
    Allocator allocator;
    allocator.makeAllocator(20);
    assert(allocator.alloc(10) != nullptr);
    assert(allocator.alloc(100) == nullptr);
    allocator.makeAllocator(100);
    assert(allocator.alloc(100) != nullptr);
    assert(allocator.alloc(1) == nullptr);
}


int main(){
    ManyAllocTest();
    ResetTest();
    ReMakeAllocatorTest();
    std::cout << "All test passed!" << std::endl;
    return 0;
}