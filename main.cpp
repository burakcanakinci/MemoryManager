#include "MemoryManager.h"

int main() {
    
    int memorySize = 20;
    MemoryManager memoryManager(memorySize);

    int choice;
    do {
        std::cout << "\nMemory Manager Simulator Menu:\n";
        std::cout << "0. Set memory size\n1. Allocate (First Fit)\n2. Allocate (Best Fit)\n3. Deallocate\n4. Display Memory\n5. Exit\n";
        std::cout << "Enter command: ";
        std::cin >> choice;

        switch(choice) {
            case 0: {
                        int newSize;
                        std::cout << "Set memory size: ";
                        std::cin >> newSize;
                        memoryManager.setMemorySize(newSize); 
                        break;
                    }
            case 1: {
                        int processId, size;
                        std::cout << "Enter process ID (e.g 1) and size (e.g 2) for allocation: ";
                        std::cin >> processId >> size;
                        memoryManager.allocateFirstFit(processId, size);
                        break;
            }
            case 2: {
                        int processId, size;
                        std::cout << "Enter process ID (e.g 2) and size (e.g 3) for allocation: ";
                        std::cin >> processId >> size;
                        memoryManager.allocateBestFit(processId, size);
                        break;
            }
            case 3: {
                        int processId;
                        std::cout << "Enter process ID for deallocation: ";
                        std::cin >> processId;
                        memoryManager.deallocate(processId);
                        break;
            }
            case 4:     memoryManager.displayMemory();
                        break;

            case 5:     std::cout << "Exiting the Memory Manager Simulator.\n";
                        break;

            default:    std::cout << "Invalid choice. Please enter a valid option.\n";
                        break;
        }

    }   while (choice != 5);

    return 0;
}

