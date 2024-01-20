#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <iostream>
#include <vector>
#include <limits>

class MemoryManager {
private:
    std::vector<bool> memory; // Represents memory blocks (ture for allocated, false for free)
public:
    MemoryManager(int size);

    // Allocate memory using First Fit algorithm
    bool allocateFirstFit(int processId, int size);

    // Allocate memory using Best Fit algorithm
    bool allocateBestFit(int processId, int size);

    // Deallocate memory
    void deallocate(int processId);

    // Display the current state of memory
    void displayMemory() const;
};

#endif // MEMORY_MANAGER_H
