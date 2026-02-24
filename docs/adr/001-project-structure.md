# ADR 001: Modular Monorepo Structure

## Status
Accepted

## Context
Theory of Computation assignments often build upon each other (e.g., creating an Alphabet leads to Strings, which leads to Languages and Automata). Writing standalone files leads to code duplication and maintenance issues.

## Decision
We will implement a shared library (`libtheory`) within the project. Each practice will be a separate module that links against this library.

## Consequences
- **Pros**: Reduced duplication, easier debugging of core logic, consistent CLI interface.
- **Cons**: Slightly more complex `Makefile` compared to single-file compilation.
