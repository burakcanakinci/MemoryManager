# Memory Manager Simulator

This is a simple C++ program that simulates a memory manager with the ability to allocate and deallocate memory using First Fit and Best Fit algorithms. Users can interact with the simulator through a console-based menu.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building the Project](#building-the-project)
- [Usage](#usage)
- [Menu Options](#menu-options)
- [Example Scenario](#example-scenario)
- [Contributing](#contributing)
- [License](#license)

## Features

- Memory allocation using First Fit and Best Fit algorithms
- Dynamic resizing of memory
- Deallocating memory
- Displaying the current state of memory

## Getting Started

### Prerequisites

- C++ compiler (GCC, MinGW, or equivalent)
- CMake (for building with CMake)
- Make (for building with Make)

### Building the Project

1. Clone the repository:

```bash
git clone https://github.com/your-username/memory-manager-simulator.git
cd memory-manager-simulator
```

2. Build the project:

- Using CMake:
```bash
mkdir build
cd build
cmake ..
make
```

- Without CMake
```bash
g++ -c MemoryManager.cpp -o MemoryManager.o
g++ -c main.cpp -o main.o
g++ MemoryManager.o main.o -o MemoryManagerSimulator
```

### Usage

Run the compiled executable:

```bash
./MemoryManagerSimulator
```
Follow the on-screen menu to perform memory operations.

## Menu Options

0. Set memory size: Set the size of the memory at runtime.
1. Allocate (First Fit): Allocate memory for a process using the First Fit algorithm.
2. Allocate (Best Fit): Allocate memory for a process using the Best Fit algorithm.
3. Deallocate: Deallocate memory previously allocated for a process.
4. Display Memory: Display the current state of memory.
5. Exit: Exit the Memory Manager Simulator.
 
## Example Scenario

1. Set memory size to 30.
2. Allocate Process 1 (size: 5) using First Fit.
3. Allocate Process 2 (size: 8) using Best Fit.
4. Display current memory state.
5. Deallocate Process 1.
6. Display current memory state.
7. Exit.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.
