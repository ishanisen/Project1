# Dal Eng Student Database  

> A C++ object-oriented student database system for Dalhousie Engineering students, featuring inheritance, a custom doubly linked list, and a menu-driven interface.  

## 📌 Features  
- **Object-Oriented Design** using inheritance and polymorphism  
  - `daleng` (base class for all students)  
  - `scholar` (derived class for scholarship students)  
  - `selffunded` (derived class for self-funded students)  
- **Custom Doubly Linked List** implementation (no STL containers).  
- **Menu-driven Interface** for easy navigation.  
- **Student Categories:**  
  - Scholarship students  
  - Self-funded students  
  - Non-categorized (base class only)  
- Supports key operations:  
  - Add student  
  - Display student records  
  - Search student  
  - Delete student  

## ⚙️ Design & Implementation  
- Built entirely in **C++** with OOP principles.  
- Database storage handled via a **linked list** (dynamic memory).  
- Includes **error handling** for edge cases (invalid inputs, empty lists, etc.).  
- UML diagrams and design documentation included in the report.  

## ✅ Testing  
- Verified with multiple test cases for each operation.  
- Checked for **memory leaks** and handling of invalid operations.  

## 🎯 Use Case  
This project simulates a **simple student management system** that can be adapted to larger educational administration tools.  
It highlights **object-oriented programming, data structures, and system design skills**.  

## 🚀 Getting Started  

### Prerequisites  
- C++ Compiler (e.g., `g++` or MSVC)  
- Command line / terminal access  

### Compilation  
```bash
g++ main.cpp daleng.cpp scholar.cpp selffunded.cpp -o student_db
