#pragma once
#include <stdexcept>
#include <cstring>

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
            memStart = new std::byte[size]{};
            numBytes = size;

            front = memStart;
        }
        std::byte* align(std::byte* addr, size_t alignment)
        {
            auto numericAddr = reinterpret_cast<uintptr_t>(addr);
            auto algnedAddr = (numericAddr + alignment - 1) & ~(alignment - 1);
            return reinterpret_cast<std::byte*>(algnedAddr);
        }
        MemoryBlock requestMemory(size_t sizeOfBlock, size_t alignment)
        {
            //Taking into account where front ends u

            //Check if we have enough memory left to allocate sizeOfBlock amount of mem
            if(amountAllocated + sizeOfBlock > numBytes)
            {
                throw std::invalid_argument("size of requested memory large than memory available");
            }

            MemoryBlock newBlock = MemoryBlock(sizeOfBlock, front, front+sizeOfBlock);


            //This feels trashy and probaly is but it works. ALign front pointer get padding for accurate memNav with padding in mind
            std::byte* alignedFront = align(front, alignment);
            size_t padding =  reinterpret_cast<size_t>(alignedFront) - reinterpret_cast<size_t>(front);
            

            memset(front,0, sizeOfBlock+padding);

            amountAllocated += (sizeOfBlock +padding);

        

            front += sizeOfBlock;
            
        
            
            

            return newBlock;
        }
        void freeBlock(MemoryBlock toFree)
        {
            if(front == toFree.getEnd())
                front = toFree.getStart();
            else
                std::cout << "Can only free most recently allocated block\n";
            return; 
        }
        //Ban copy constructor and copy assignment
        Allocator(const Allocator&) = delete;
        Allocator& operator = (const Allocator&) = delete;
        
        ~Allocator()
        {
            delete[] memStart;
        }

    

};