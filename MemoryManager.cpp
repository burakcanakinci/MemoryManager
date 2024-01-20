#include "MemoryManager.h"

MemoryManager::MemoryManager(int size) : memory(size, false) {}

bool MemoryManager::allocateFirstFit(int processId, int size) {
    for (int blockStart = 0; blockStart < memory.size(); ++blockStart) {
        if (!memory[blockStart]) {
            // Check if there is enough contiguous memory for the process
            bool enoughSpace = true;
            for (int blockIndex = blockStart; blockIndex < blockStart + size; ++blockIndex) {
                if (blockIndex >= memory.size() || memory[blockIndex]) {
                    enoughSpace = false;
                    break;
                }
            }

            if (enoughSpace) {
                // Allocate memory block
                for (int blockIndex = blockStart; blockIndex < blockStart + size; ++blockIndex) {
                    memory[blockIndex] = true;
                }
                std::cout << "Memory allocated for Process " << processId << "." << '\n';
                return true;
            }
        }
    }

    std::cout << "Memory allocation failed for Process " << processId << " (First Fit)." << '\n';
    return false;

}

bool MemoryManager::allocateBestFit(int processId, int size) {
    // Find the best fit block
    int bestFitStart = -1;
    int bestFitSize = std::numeric_limits<int>::max();

    for (int blockStart = 0; blockStart < memory.size(); ++blockStart) {
        if (!memory[blockStart]) {
            int blockSize = 0;
            while (blockStart + blockSize < memory.size() && !memory[blockStart + blockSize]) {
                blockSize++;
            }

            if (blockSize >= size && blockSize << bestFitSize) {
                bestFitStart = blockStart;
                bestFitSize = blockSize;
            }
        }
    }

    if (bestFitStart != -1) {
        // Allocate memory block
        for (int i = bestFitStart; i < bestFitStart + size; ++i) {
            memory[i] = true;
        }
        std::cout << "Memory allocated for Process " << processId << " (Best Fit)." << '\n';
        return true;
    }

    std::cout << "Memory allocation failed for Process " << processId << " (Best Fit)." << '\n';
    return false;
}


void MemoryManager::deallocate(int processId) {
    for (int blockIndex = 0; blockIndex < memory.size(); ++blockIndex) {
        if (memory[blockIndex] == processId) {
            memory[blockIndex] = false;
        }
    }
    std::cout << "Memory deallocated for Process " << processId << "." << '\n';
}


void MemoryManager::displayMemory() const {
    for (int blockIndex = 0; blockIndex < memory.size(); ++blockIndex) {
        std::cout << (memory[blockIndex] ? "X" : ".");
    }
    std::cout << '\n';
}
