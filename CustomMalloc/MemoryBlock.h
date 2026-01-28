#pragma once

#include <cstddef>

class MemoryBlock
{
private:
    std::byte* start;
    std::byte* end;
    size_t size;
    size_t numElem;

public:
    MemoryBlock(size_t sze, std::byte* strt, std::byte* en);

    int getSize() const;
    int getNumberOfElements() const;
    std::byte* getStart() const;

    std::byte getByteAt(size_t i) const;
    int setByteAt(size_t i, std::byte n);
};
