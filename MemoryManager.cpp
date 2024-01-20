#include "MemoryManager.h"

MemoryManager::MemoryManager(int size) : memory(size, false) {}

bool MemoryManager::allocateFirstFit(int processId, int size) {
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i]) {
            // Check if there is enough contiguous memory for the process
            bool enoughSpace = true;
            for (int j = i; j < i + size; ++j) {
                if (j >= memory.size() || memory[j]) {
                    enoughSpace = false;
                    break;
                }
            }

            if (enoughSpace) {
                // Allocate memory block
                for (int j = i; j < i + size; ++j) {
                    memory[j] = true;
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

    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i]) {
            int blockSize = 0;
            while (i + blockSize < memory.size() && !memory[i + blockSize]) {
                blockSize++;
            }

            if (blockSize >= size && blockSize << bestFitSize) {
                bestFitStart = i;
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
    for (int i = 0; i < memory.size(); ++i) {
        if (memory[i] == processId) {
            memory[i] = false;
        }
    }
    std::cout << "Memory deallocated for Process " << processId << "." << '\n';
}


void MemoryManager::displayMemory() const {
    for (int i = 0; i < memory.size(); ++i) {
        std::cout << (memory[i] ? "X" : ".");
    }
    std::cout << '\n';
}
