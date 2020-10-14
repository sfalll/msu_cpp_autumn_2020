#include <iostream>
#include <cassert>
#include "allocator.hpp"

void ManyAllocTest(){
    Allocator allocator;
    allocator.MakeAllocator(20);
    assert(allocator.Alloc(10) != nullptr);
    assert(allocator.Alloc(8) != nullptr);
    assert(allocator.Alloc(0) == nullptr);
    assert(allocator.Alloc(1) != nullptr);
    assert(allocator.Alloc(2) == nullptr);
    assert(allocator.Alloc(1) != nullptr);
    assert(allocator.Alloc(1) == nullptr);
}

void ResetTest(){
    Allocator allocator;
    allocator.MakeAllocator(20);
    assert(allocator.Alloc(10) != nullptr);
    assert(allocator.Alloc(11) == nullptr);
    allocator.Reset();
    assert(allocator.Alloc(11) != nullptr);
}

void ReMakeAllocatorTest(){
    Allocator allocator;
    allocator.MakeAllocator(20);
    assert(allocator.Alloc(10) != nullptr);
    assert(allocator.Alloc(100) == nullptr);
    allocator.MakeAllocator(100);
    assert(allocator.Alloc(100) != nullptr);
    assert(allocator.Alloc(1) == nullptr);
}


int main(){
    ManyAllocTest();
    ResetTest();
    ReMakeAllocatorTest();
    std::cout << "All test passed!" << std::endl;
    return 0;
}