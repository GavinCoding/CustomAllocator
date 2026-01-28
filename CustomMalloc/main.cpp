#include <iostream>
#include "Allocator.h"
#include "MemoryBlock.h"

int main()
{
    Allocator myAllocator(1000);

    try {
        // Allocate first block
        MemoryBlock blockA = myAllocator.requestMemory(100);
        MemoryBlock blockB = myAllocator.requestMemory(50);

        // Write some data
        for (size_t i = 0; i < blockA.getSize(); ++i)
            blockA.setByteAt(i, static_cast<std::byte>(i % 256));

        for (size_t i = 0; i < blockB.getSize(); ++i)
            blockB.setByteAt(i, static_cast<std::byte>((i + 100) % 256));

        // Print blockA
        std::cout << "Block A contents:\n";
        for (size_t i = 0; i < blockA.getSize(); ++i)
            std::cout << static_cast<unsigned int>(blockA.getByteAt(i)) << " ";
        std::cout << "\n\n";

        // Print blockB
        std::cout << "Block B contents:\n";
        for (size_t i = 0; i < blockB.getSize(); ++i)
            std::cout << static_cast<unsigned int>(blockB.getByteAt(i)) << " ";
        std::cout << "\n\n";

        // Free last block (blockB) → should succeed
        std::cout << "Freeing block B (last allocated)...\n";
        myAllocator.freeBlock(blockB);

        // Attempt to free blockA → should succeed now because it is the last allocated
        std::cout << "Freeing block A (now last allocated)...\n";
        myAllocator.freeBlock(blockA);

        // Allocate another block to test reuse after free
        MemoryBlock blockC = myAllocator.requestMemory(50);
        std::cout << "Allocated block C of size " << blockC.getSize() << "\n";

        // Write to blockC to verify memory is zeroed
        std::cout << "Block C initial contents (should be 0):\n";
        for (size_t i = 0; i < blockC.getSize(); ++i)
            std::cout << static_cast<unsigned int>(blockC.getByteAt(i)) << " ";
        std::cout << "\n";

    } catch (const std::invalid_argument& e) {
        std::cerr << "Allocation error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
