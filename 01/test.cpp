#include <iostream>
#include <cassert>
#include "allocator.hpp"

int main(){
    Allocator allocator;
    allocator.makeAllocator(10);
    assert(allocator.alloc(9) != nullptr);
    std::cout << (allocator.alloc(9) == nullptr) << std::endl;
    return 0;
}