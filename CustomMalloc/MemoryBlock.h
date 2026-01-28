#pragma once

#include <cstddef>


class MemoryBlock
{
    private:
        //pointer to start of block
        std::byte* start;
        //pointer to end of block
        std::byte* end;

        //1. Use Enum for type?
        //2. Use type of somehow

        //size of  block
        size_t size;
        //number of elements inside
        size_t numElem;

    public:
        int getSize()
        {
            return size;
        }
        int getNumberOfElements()
        {
            return numElem;
        }
        std::byte* getStart()
        {
            return start;
        }
        std::byte* getEnd()
        {
            return end;
        }
        //Allocator will be in charge of MemoryBlock allocation. That is that we will use the allocator to return objects of Memory blocks

        MemoryBlock(size_t sze, std::byte* strt, std::byte* en)
        {
            size = sze;
            start = strt;
            end = en;
        }


        std::byte getByteAt(size_t i)
        {
            if(i >= size)
            {
                return (std::byte)17;
            }
            return *(start+i);
        }

        int setByteAt(size_t i, std::byte n)
        {
            if(i >= size)
            {
                return -1;
            }
            *(start+i) = n;
            return 0;

        }
        ~MemoryBlock() {}
        
    //Data type + data size of type
    //number of types

};