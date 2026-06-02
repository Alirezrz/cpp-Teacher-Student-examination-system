# 🏫 C++ Academic Portal & Examination System

A robust, terminal-based academic portal and dynamic exam management engine built from scratch using **Object-Oriented Programming (OOP)** principles in C++. The system isolates permissions between **Teachers** and **Students** to facilitate live exam configuration, automated grading, and persistent JSON data management.

---

## 🛠️ System Architecture & Code Breakdown

The project relies on a modular, clean header-implementation architecture mapping realistic real-world academic objects:

### 👤 Core Entities & Access Control
* **`Person` (Base Class):** Establishes core demographic parameters (`Name`, `ID`, `Password`) alongside unified console behaviors like string trimming and global session exit handlers.
* **`Teacher` (Derived Class):** Grants administrative access to design course matrices, generate randomized test scripts, and manually review or override complex student grades.
* **`Student` (Derived Class):** Permits individual user authentication to register for fields of study, launch real-time test clocks, and request individual grade sheet summaries.

### 📝 Examination & Evaluation Engine
* **`Question`:** Supports multiple testing formats including **Multiple Choice (Tests)**, **Short Answer**, and **Long Form (Essay)** inputs. Implements distinct positive scoring constraints and negative grading penalties.
* **`Exam`:** Combines questions into unique structural objects with administrative runtime limits (automated countdown counters) and automated output streams.
* **`ReportCard`:** Handles real-time post-exam diagnostics, creating clean visual logs mapping *Question -> Student Answer -> Answer Template -> Validation Flag* with unified terminal color metrics.

### 💾 Persistence & Core Drivers
* **`system.cpp`:** The master orchestrator. Loads data structures safely on boot, renders the administrative UI menus, tracks security session tokens, and executes clean memory allocation deletions upon program exit.
* **`json.hpp`:** Integrates the `nlohmann/json` engine to save and re-parse user accounts, course data, and exam metrics across terminal sessions.

---

## 🚀 Key Technical Features Highlighted

* **Object-Oriented Principles:** Strong implementation of **Inheritance** (Person ➔ Student/Teacher) and encapsulated data schemas to secure sensitive operations.
* **STL Container Utilizations:** Heavily leverages standard vectors, string manipulation templates, and cryptographic/time utilities (`<chrono>`) to build stable, reactive features.
* **Terminal Diagnostics & Reporting:** Auto-calculates key statistical parameters upon exam completion, dynamically printing class metrics such as **Class Highest Score** and **Group Performance Averages**.

---

## 💻 Tech Stack Used

* **Language:** Modern C++ (C++11 / C++14)
* **Data Serialization:** JSON File-based parsing (`nlohmann/json`)
* **Operating Systems:** Cross-platform support (Windows/Linux UI adjustments)

---

## 🏗️ How to Build and Run Locally

Ensure you have a modern C++ compiler (like GCC/MinGW) configured on your environment path.

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Alirezrz/cpp-Teacher-Student-examination-system.git
   cd cpp-examination-system