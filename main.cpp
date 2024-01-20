#include "MemoryManager.h"

int main() {
    // Create a Memory Manager with 20 block of memory
    MemoryManager memoryManager(20);

    // Simulate memory allocation and deallocation
    memoryManager.displayMemory();

    if (memoryManager.allocateFirstFit(1,3)) {
        memoryManager.displayMemory();
    }

    if (memoryManager.allocateFirstFit(2,5)) {
        memoryManager.displayMemory();
    }

    
}

