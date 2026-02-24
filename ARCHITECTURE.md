# Project Architecture

## Overview
This project uses a **Modular Monorepo** approach. Instead of writing isolated programs for each assignment, common mathematical concepts of Theory of Computation are abstracted into a shared library.

## Directory Structure

- `include/`: Global header files defining the shared API.
- `src/shared/`: Implementation of core formal language structures (Alphabets, States, Transitions).
- `src/practiceX/`: Entry points for specific course assignments.
- `bin/`: Compiled executables and objects (git-ignored).

## Design Principles
1. **Reusability**: Logic defined in `src/shared` (like NFA to DFA conversion) must be accessible to all future practices.
2. **Encapsulation**: Use of `structs` to represent formal definitions like $M = (Q, \Sigma, \delta, q_0, F)$.
3. **Automated Build**: A single `Makefile` handles dependency linking between shared logic and specific practice mains.
