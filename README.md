
# Students' Grades BST

**Students' Grades BST** is a C++ project that uses a **Binary Search Tree (BST)** and **Linked Lists** to efficiently manage and organize student grades. It allows users to store subjects (e.g., courses) in a BST, with each subject node containing a linked list of grades. Key functionalities include inserting, removing, and searching for subjects and grades, as well as calculating the maximum grade across all subjects.

## Features

- **Subject Management**:
  - Insert new subjects.
  - Remove existing subjects.
  - Search for subjects.

- **Grade Management**:
  - Insert grades for a subject.
  - Remove grades from a subject.
  - Calculate the maximum grade across all subjects.

- **Display**:
  - Print all subjects and their grades in sorted order.
  - Display the average grade for each subject.

## How It Works

- **BST Structure**: Each node represents a subject and contains a linked list of grades.
- **Linked Lists**: Grades are stored in sorted linked lists for efficient management.
- **In-Order Traversal**: Subjects and grades are displayed in sorted order.

## Example Usage

- Add a subject: `insertSubject("Math")`
- Add a grade: `insertGradeForSubject("Math", 90)`
- Remove a grade: `removeGradeForSubject("Math", 90)`
- Remove a subject: `removeSubject("Math")`
- Print all subjects and grades: `printSubjects()`
- Find the maximum grade: `maxGradeInAll()`

## Why This Project?

This project demonstrates the practical application of **Binary Search Trees** and **Linked Lists** for managing hierarchical and sequential data, such as student grades.

---

## Getting Started

### Prerequisites

- C++ compiler (supporting C++17 or higher)
- CMake (for building the project)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/Students-Grades-BST.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Students-Grades-BST
   ```
3. Build the project using CMake:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```
4. Run the executable:
   ```bash
   ./build/Studeeennt_GRAdddess
   ```

---

## Contributing

Contributions are welcome! If you have suggestions, bug reports, or feature requests, please open an issue or submit a pull request.
