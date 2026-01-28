#pragma once
#include <stdexcept>

#include "MemoryBlock.h"

class Allocator{
    private:

        std::byte* memStart{};
        size_t numBytes{};
        // bool free[500]{true};

        std::byte* front;

        size_t amountAllocated{};

    public:
        Allocator(size_t size)
        {
            memStart = new std::byte[size];
            numBytes = size;

            front = memStart;
        }
        MemoryBlock requestMemory(size_t sizeOfBlock)
        {
            //Check if we have enough memory left to allocate sizeOfBlock amount of mem
            if(amountAllocated + sizeOfBlock > numBytes)
            {
                throw std::invalid_argument("size of requested memory large than memory available");
            }

            MemoryBlock newBlock = MemoryBlock(sizeOfBlock, front, front+sizeOfBlock);
            front += sizeOfBlock;
            amountAllocated += sizeOfBlock;

            return newBlock;
        }

    

};