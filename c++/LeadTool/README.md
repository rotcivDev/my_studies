# WebLead Tool

## Overview

A C++ CLI app to manage web leads, using PostgreSQL and Docker with layered architecture.

## Architecture

- CLI: Input/output handling
- App: Control flow dispatcher
- Services: Business logic
- Infrastructure: DB interaction
- SQL: Schema, fully decoupled

┌────────────────────────────┐
│ CLI I/O │ ◄── User Interface (CLI)
└────────────┬───────────────┘
▼
┌────────────────────────────┐
│ Application │ ◄── App layer: command dispatch, control flow
└────────────┬───────────────┘
▼
┌────────────────────────────┐
│ Services │ ◄── Business logic
└────────────┬───────────────┘
▼
┌────────────────────────────┐
│ Infrastructure │ ◄── Repositories & PostgreSQL
└────────────┬───────────────┘
▼
┌────────────────────────────┐
│ SQL Schema/Files │ ◄── Pure SQL queries
└────────────────────────────┘

weblead-tool/
├── CMakeLists.txt
├── bin/
├── build/
├── sql/
│ └── schema.sql
├── src/
│ ├── cli/
│ │ └── main.cpp
│ ├── app/
│ │ └── dispatcher.cpp
│ ├── services/
│ │ └── lead_service.cpp
│ ├── infrastructure/
│ │ └── lead_repository.cpp
│ └── common/
│ └── db_connection.cpp
└── include/
└── ...

## Commands

- add: Add a new lead
- list: List all leads
- search: Find leads by keyword
- delete: Remove a lead by ID
- export: Save all leads as JSON

## Build

```bash
cmake -Bbuild
cmake --build build
./build/weblead
```

## Docker

Run the app:

```bash
docker-compose up --build
```

## Tests

Run tests via `tests/test_cli.cpp` using Catch2

## License

MIT

