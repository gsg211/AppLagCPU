# Documentation

## 1. Timing & Synchronization

The `Timing` module manages the system clock and thread synchronization using a producer-consumer pattern.

### Timing Class

Controls the execution heartbeat of the system.

* **Thread Management:** Uses `std::jthread` for RAII-compliant thread management.
* **Synchronization:** Utilizes a mutex and condition variable to signal "ticks" to dependent components.

```mermaid
classDiagram
    class Timing {
        -m_timingMutex: std::mutex
        -m_timingConditionVariable: std::condition_variable
        -m_tick: std::atomic_bool
        -m_timingThread: std::jthread
        -m_running: std::atomic_bool
        +Timing()
        +~Timing()
        +start() void
        +stop() void
        +TimingConditionVariable() std::condition_variable&
        +TimingMutex() std::mutex&
        +IsActive() bool
        -run() void
    }

    class TimingPtr <<typedef>>
    TimingPtr ..> Timing : points to

```

---

## 2. Hardware Layer

These classes represent the physical-level emulation of the processor and memory.

### Memory & Registers


| Component | Responsibility |
| --- | --- |
| **Memory** | Handles byte/word access and atomic state flags for read/write operations. |
| **RegisterBank** | Manages 8 general-purpose registers, the IP (Instruction Pointer), and SP (Stack Pointer). |

```mermaid
classDiagram 
    class Memory {
        -cpu_memory: std::array<std::array<uint8_t, 8>, 8192>
        +memRead: std::atomic_bool
        +memWrite: std::atomic_bool
        +getLine(uint16_t address) std::array<uint8_t,8>&
        +readWord(uint16_t address) uint16_t
        +readByte(uint16_t address) uint8_t
        +loadWord(uint16_t address, uint16_t value) void
        +loadByte(uint16_t address, uint8_t value) void
    }

    class RegisterBank {
        -registerBank: std::array<uint16_t, 8>
        -instructionPointer: uint16_t
        -stackPointer: uint16_t
        -flagRegister: uint16_t
        +setRegisterValue(uint16_t id, uint16_t val) void
        +getRegisterValue(uint16_t id) uint16_t
        +setStackPointer(uint16_t val) void
        +getInstructionPointer() uint16_t
        +setFlagRegisterFlag(uint16_t id, bool val) void
    }

```

### CPU Architecture

The CPU follows a standard **Control Path** and **Data Path** separation.

* **DataPath:** Orchestrates the Fetch/Decode/Execute cycle.
* **Execute Unit:** Interfaces directly with the **ALU** to perform arithmetic and logic operations.

```mermaid
classDiagram
    class CPU {
        +dataPath: DataPath
        +controlPath: ControlPath
    }

    class DataPath {
        +fetch()
        +decode()
        +execute()
        +registerBank: RegisterBank
    }

    class Execute {
        -ALUSrcA: uint16_t
        -ALUSrcB: uint16_t
        -alu: Alu
        +setAluSourceA(val)
        +getAluResult()
    }

    class Alu {
        +add()
        +sub()
        +mul()
        +div()
        +cmp()
    }

    CPU *-- DataPath
    CPU *-- ControlPath
    DataPath *-- Execute
    Execute *-- Alu

```

---

## 3. Utilities & Messaging

Inter-module communication.

### Message Struct

Used to pass data between components or external interfaces.

```mermaid
classDiagram
class Message <<Struct>> {
    +m_messageType: std::string
    +m_msgData: uint8_t
}

```
