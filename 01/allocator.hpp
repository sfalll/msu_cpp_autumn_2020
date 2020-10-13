#include <cstddef>

class Allocator{
private:
    size_t maxSize_ = 0, offset_ = 0;
    char* start_ = nullptr;
public:
    ~Allocator();
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
};