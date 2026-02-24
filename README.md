# Theory of Computation - Practice Repository

This repository contains the implementations for the **Theory of Computation** course. It is designed as a modular C project to reuse core logic across different assignments.

## Prerequisites

- **Docker**: The project is designed to run inside a [DevContainer](https://code.visualstudio.com/docs/devcontainers/containers).
- **VS Code**: Recommended for seamless integration with the containerized environment.

## Getting Started

1. Open this folder in VS Code.
2. When prompted, click **"Reopen in Container"**.
3. Once the environment is ready, you can build any practice using the `Makefile`.

## Build Instructions

To build a specific practice (e.g., practice 1):
```bash
make practice1
./bin/practice1_exe
