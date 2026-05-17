# Student Management System - C++

A comprehensive console-based Student Management System with file handling and menu-driven operations.

## Features

### Core Functionality
- ✅ **Add New Student** - Add student records with validation
- ✅ **Display All Students** - View all students in a formatted table
- ✅ **Search Student** - Find student by roll number
- ✅ **Update Student Record** - Modify existing student information
- ✅ **Delete Student Record** - Remove student with confirmation
- ✅ **Display Statistics** - View average marks, top student, etc.
- ✅ **Filter by Course** - Display students enrolled in a specific course

### Technical Features
- **File Persistence** - All data saved to `students.txt`
- **Data Validation** - Prevents duplicate roll numbers
- **Grade Calculation** - Automatic grade assignment based on marks
- **Input Validation** - Robust error handling for user inputs
- **Formatted Output** - Clean, table-based display with proper alignment

## Student Data Structure

Each student record contains:
- **Roll Number** (unique identifier)
- **Name**
- **Course**
- **Marks** (0-100)
- **Email**
- **Grade** (auto-calculated: A+, A, B+, B, C, D, F)

## Compilation & Execution

### Option 1: Using g++
```bash
g++ -std=c++11 student_management_system.cpp -o student_system
./student_system
```

### Option 2: Using g++ with optimization
```bash
g++ -std=c++11 -O2 student_management_system.cpp -o student_system
./student_system
```

### Option 3: Using clang++ (if available)
```bash
clang++ -std=c++11 student_management_system.cpp -o student_system
./student_system
```

## Usage Guide

### 1. Adding a Student
- Select option `1` from the menu
- Enter roll number, name, course, marks, and email
- System validates for duplicate roll numbers
- Record is automatically saved to file

### 2. Viewing All Students
- Select option `2`
- Displays a formatted table with all student records
- Shows total student count

### 3. Searching for a Student
- Select option `3`
- Enter the roll number
- Displays detailed information including calculated grade

### 4. Updating Student Information
- Select option `4`
- Enter the roll number to update
- View current details
- Enter new information (press Enter to keep current values)

### 5. Deleting a Student
- Select option `5`
- Enter the roll number
- Confirm deletion (y/n)
- Record is removed from file

### 6. Viewing Statistics
- Select option `6`
- Displays:
  - Total number of students
  - Average marks
  - Highest marks
  - Lowest marks
  - Top performing student

### 7. Filtering by Course
- Select option `7`
- Enter course name
- Displays all students in that course

## Grading System

| Marks Range | Grade |
|-------------|-------|
| 90-100      | A+    |
| 80-89       | A     |
| 70-79       | B+    |
| 60-69       | B     |
| 50-59       | C     |
| 40-49       | D     |
| 0-39        | F     |

## File Structure

```
student_management_system.cpp    # Main source code
students.txt                     # Data file (auto-generated)
README.md                        # Documentation
```

## Data Persistence

- All student records are stored in `students.txt`
- Data is automatically loaded when the program starts
- Changes are immediately saved to the file
- File format: Plain text with one field per line

## Example Session

```
╔════════════════════════════════════════════╗
║   STUDENT MANAGEMENT SYSTEM                ║
╚════════════════════════════════════════════╝
  1. Add New Student
  2. Display All Students
  3. Search Student
  4. Update Student Record
  5. Delete Student Record
  6. Display Statistics
  7. Display Students by Course
  8. Exit

Enter your choice: 1

--- Enter Student Details ---
Enter Roll Number: 101
Enter Name: John Doe
Enter Course: Computer Science
Enter Marks (0-100): 85.5
Enter Email: john.doe@example.com

✓ Student record added successfully!
```

## Error Handling

The system includes robust error handling for:
- Invalid menu choices
- Non-numeric inputs
- Duplicate roll numbers
- File I/O errors
- Missing student records

## Requirements

- C++11 or higher
- Standard C++ library
- Any modern C++ compiler (g++, clang++, MSVC)

## System Compatibility

- ✅ Linux
- ✅ macOS
- ✅ Windows (with MinGW or Visual Studio)

## Future Enhancements

Potential features for expansion:
- Sort students by name, marks, or roll number
- Export data to CSV format
- Import data from external files
- Password protection for admin operations
- Attendance tracking
- Fee management
- Report card generation

## License

Free to use for educational purposes.

## Author

Created as a demonstration of C++ file handling and object-oriented programming principles.
