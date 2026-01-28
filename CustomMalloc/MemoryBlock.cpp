#include "MemoryBlock.h"

MemoryBlock::MemoryBlock(size_t sze, std::byte* strt, std::byte* en)
    : start(strt), end(en), size(sze), numElem(0)
{
}

int MemoryBlock::getSize() const
{
    return size;
}

int MemoryBlock::getNumberOfElements() const
{
    return numElem;
}

std::byte* MemoryBlock::getStart() const
{
    return start;
}

std::byte MemoryBlock::getByteAt(size_t i) const
{
    if (start + i >= end)
    {
        return std::byte{17}; // sentinel (fine for now)
    }
    return *(start + i);
}

int MemoryBlock::setByteAt(size_t i, std::byte n)
{
    if (start + i >= end)
    {
        return -1;
    }
    *(start + i) = n;
    return 0;
}



