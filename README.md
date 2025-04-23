# Philosophers

# Philosophers Problem Project

A solution for the classic dining philosophers problem, implemented using POSIX threads and mutexes in C.

### Table of Contents

- [Overview](#overview)
- [The Problem](#the-problem)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Implementation Details](#implementation-details)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Author](#author)

## Overview

This project implements a solution to the dining philosophers problem, a classic synchronization and concurrency problem that illustrates the challenges of resource allocation and deadlock avoidance in concurrent systems.

## The Problem

The dining philosophers problem consists of:

- N philosophers sitting around a circular table
- A fork placed between each pair of adjacent philosophers
- Each philosopher needs two forks to eat (the ones to their left and right)
- Philosophers alternate between thinking, eating, and sleeping

The challenge is to design a solution where:

- No philosopher will starve
- The program avoids deadlocks (where all philosophers hold one fork and wait forever for another)
- The program avoids data races and ensures proper synchronization

## Installation

Clone the repository and compile the project:

```bash
git clone <https://github.com/thenew-programer/philosophers.git>
cd philosophers
make
```

## Usage

Run the program with the following arguments:

```bash
bash./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Parameters

- `number_of_philosophers`: The number of philosophers and forks (1 to 200)
- `time_to_die`: Time in milliseconds after which a philosopher dies if they haven't started eating
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat
- `time_to_sleep`: Time in milliseconds a philosopher will spend sleeping
- `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation stops when all philosophers have eaten at least this many times

### Examples

```bash

# 5 philosophers, 800ms to die, 200ms to eat, 200ms to sleep
./philo 5 800 200 200
# 4 philosophers, must each eat at least 5 times

./philo 4 410 200 200 5
```

## Features

- Thread-safe implementation using mutexes
- Color-coded console output for different philosopher states
- Deadlock prevention through resource hierarchy
- Proper cleanup of allocated resources

## Implementation Details

### Resource Management

- Each fork is represented by a mutex
- Even-numbered philosophers take their left fork first, odd-numbered philosophers take their right fork first (preventing deadlock)
- A philosopher must hold both forks to eat

### Thread Architecture

- Each philosopher runs in its own thread
- A separate monitor thread checks for philosopher deaths or completion conditions
- Mutexes protect shared resources from race conditions

### Error Handling

- Proper validation of input parameters
- Safe cleanup of resources in error cases and on program termination
- Mutex locking/unlocking protection pattern to ensure safe thread termination

## Testing

Run the included test suite:

```bash
make test
```

The test suite checks various scenarios including:

- Deadlock detection
- Race condition detection using Helgrind
- Basic functionality tests
- Edge cases like a single philosopher

## Project Structure

```
.
├── inc/
│ └── philo.h # Header file with structures and function declarations
├── src/
│ ├── actions.c # Philosopher actions (eat, sleep, think)
│ ├── cleanup.c # Resource cleanup functions
│ ├── main.c # Program entry point
│ ├── parser.c # Command-line argument parsing
│ ├── routines.c # Thread routines for philosophers and monitor
│ ├── simulation.c # Simulation initialization and execution
│ ├── utils_1.c # Utility functions
│ └── utils_2.c # Additional utility functions
├── Makefile # Build configuration
└── README.md # This file

```

## Author

Created by ybouryal.
