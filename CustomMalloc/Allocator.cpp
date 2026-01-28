#include <cstddef>
#include <iostream>

#include "Allocator.h"


Allocator::Allocator(size_t size)
    :memStart(new std::byte[size]),
    numBytes(size),
    front (memStart),
    amountAllocated(0)
{}
MemoryBlock Allocator::requestMemory(size_t sizeOfBlock)
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
Allocator::~Allocator()
{
    delete[] memStart;
}

int main()
{
    //make allocator
    Allocator myAllocator = Allocator(1000);

    try{
        MemoryBlock one = myAllocator.requestMemory(100);
        size_t loc;
        int num;
        while(true)
        {
            std::cin >> loc;
            std::cin >> num;
            if(one.setByteAt((size_t)loc, (std::byte)num) == 0)
            {
                std::cout << static_cast<unsigned int>(one.getByteAt(loc));
            }
            std::cout<<std::endl;
        }
        
    }
catch (const std::invalid_argument& e)
    {
        std::cout << e.what();
        return -1;
    }



}