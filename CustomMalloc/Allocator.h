#pragma once
#include <stdexcept>

#include "MemoryBlock.h"
class Allocator{
    private:
        std::byte* memStart{};
        size_t numBytes{};
        std::byte* front;
        size_t amountAllocated{};
    public:
        Allocator(size_t size);
        ~Allocator();
        MemoryBlock requestMemory(size_t sizeOfBlock);

};
