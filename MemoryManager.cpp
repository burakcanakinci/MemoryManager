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
