#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

// Student class to represent student data
class Student {
private:
    int rollNo;
    string name;
    string course;
    float marks;
    string email;

public:
    // Constructors
    Student() : rollNo(0), name(""), course(""), marks(0.0), email("") {}
    
    Student(int roll, string n, string c, float m, string e) 
        : rollNo(roll), name(n), course(c), marks(m), email(e) {}

    // Getters
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    string getCourse() const { return course; }
    float getMarks() const { return marks; }
    string getEmail() const { return email; }

    // Setters
    void setRollNo(int roll) { rollNo = roll; }
    void setName(string n) { name = n; }
    void setCourse(string c) { course = c; }
    void setMarks(float m) { marks = m; }
    void setEmail(string e) { email = e; }

    // Input student data
    void inputData() {
        cout << "\n--- Enter Student Details ---\n";
        
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks (0-100): ";
        cin >> marks;
        cin.ignore();

        cout << "Enter Email: ";
        getline(cin, email);
    }

    // Display student data
    void displayData() const {
        cout << left << setw(12) << rollNo 
             << setw(25) << name 
             << setw(20) << course 
             << setw(10) << fixed << setprecision(2) << marks 
             << setw(30) << email << endl;
    }

    // Display detailed student data
    void displayDetailedData() const {
        cout << "\n========================================\n";
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Course      : " << course << endl;
        cout << "Marks       : " << fixed << setprecision(2) << marks << endl;
        cout << "Email       : " << email << endl;
        cout << "Grade       : " << calculateGrade() << endl;
        cout << "========================================\n";
    }

    // Calculate grade based on marks
    string calculateGrade() const {
        if (marks >= 90) return "A+";
        else if (marks >= 80) return "A";
        else if (marks >= 70) return "B+";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else if (marks >= 40) return "D";
        else return "F";
    }

    // Write student data to file
    void writeToFile(ofstream &file) const {
        file << rollNo << endl;
        file << name << endl;
        file << course << endl;
        file << marks << endl;
        file << email << endl;
    }

    // Read student data from file
    void readFromFile(ifstream &file) {
        file >> rollNo;
        file.ignore();
        getline(file, name);
        getline(file, course);
        file >> marks;
        file.ignore();
        getline(file, email);
    }
};

// Student Management System class
class StudentManagementSystem {
private:
    const string filename = "students.txt";
    vector<Student> students;

    // Load all students from file
    void loadStudentsFromFile() {
        students.clear();
        ifstream file(filename);
        
        if (!file) {
            return; // File doesn't exist yet
        }

        while (file.peek() != EOF) {
            Student s;
            s.readFromFile(file);
            if (file) {
                students.push_back(s);
            }
        }
        file.close();
    }

    // Save all students to file
    void saveStudentsToFile() {
        ofstream file(filename, ios::trunc);
        
        if (!file) {
            cout << "\nError: Unable to open file for writing!\n";
            return;
        }

        for (const auto &student : students) {
            student.writeToFile(file);
        }
        file.close();
    }

    // Check if roll number already exists
    bool rollNumberExists(int rollNo) {
        return any_of(students.begin(), students.end(), 
                     [rollNo](const Student &s) { return s.getRollNo() == rollNo; });
    }

    // Find student by roll number
    int findStudentIndex(int rollNo) {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getRollNo() == rollNo) {
                return i;
            }
        }
        return -1;
    }

public:
    // Constructor
    StudentManagementSystem() {
        loadStudentsFromFile();
    }

    // Add new student
    void addStudent() {
        Student s;
        s.inputData();

        if (rollNumberExists(s.getRollNo())) {
            cout << "\nError: Student with Roll Number " << s.getRollNo() 
                 << " already exists!\n";
            return;
        }

        students.push_back(s);
        saveStudentsToFile();
        cout << "\n✓ Student record added successfully!\n";
    }

    // Display all students
    void displayAllStudents() {
        if (students.empty()) {
            cout << "\nNo student records found!\n";
            return;
        }

        cout << "\n--- All Student Records ---\n";
        cout << string(110, '=') << endl;
        cout << left << setw(12) << "Roll No" 
             << setw(25) << "Name" 
             << setw(20) << "Course" 
             << setw(10) << "Marks" 
             << setw(30) << "Email" << endl;
        cout << string(110, '-') << endl;

        for (const auto &student : students) {
            student.displayData();
        }
        cout << string(110, '=') << endl;
        cout << "Total Students: " << students.size() << endl;
    }

    // Search student by roll number
    void searchStudent() {
        int rollNo;
        cout << "\nEnter Roll Number to search: ";
        cin >> rollNo;

        int index = findStudentIndex(rollNo);
        if (index == -1) {
            cout << "\nStudent with Roll Number " << rollNo << " not found!\n";
            return;
        }

        cout << "\n✓ Student Found!\n";
        students[index].displayDetailedData();
    }

    // Update student record
    void updateStudent() {
        int rollNo;
        cout << "\nEnter Roll Number to update: ";
        cin >> rollNo;

        int index = findStudentIndex(rollNo);
        if (index == -1) {
            cout << "\nStudent with Roll Number " << rollNo << " not found!\n";
            return;
        }

        cout << "\nCurrent Details:\n";
        students[index].displayDetailedData();

        cout << "\n--- Enter New Details ---\n";
        cin.ignore();
        
        string name, course, email;
        float marks;

        cout << "Enter New Name (or press Enter to keep current): ";
        getline(cin, name);
        if (!name.empty()) {
            students[index].setName(name);
        }

        cout << "Enter New Course (or press Enter to keep current): ";
        getline(cin, course);
        if (!course.empty()) {
            students[index].setCourse(course);
        }

        cout << "Enter New Marks (or -1 to keep current): ";
        cin >> marks;
        if (marks >= 0) {
            students[index].setMarks(marks);
        }
        cin.ignore();

        cout << "Enter New Email (or press Enter to keep current): ";
        getline(cin, email);
        if (!email.empty()) {
            students[index].setEmail(email);
        }

        saveStudentsToFile();
        cout << "\n✓ Student record updated successfully!\n";
    }

    // Delete student record
    void deleteStudent() {
        int rollNo;
        cout << "\nEnter Roll Number to delete: ";
        cin >> rollNo;

        int index = findStudentIndex(rollNo);
        if (index == -1) {
            cout << "\nStudent with Roll Number " << rollNo << " not found!\n";
            return;
        }

        cout << "\nStudent to be deleted:\n";
        students[index].displayDetailedData();

        char confirm;
        cout << "\nAre you sure you want to delete this record? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            students.erase(students.begin() + index);
            saveStudentsToFile();
            cout << "\n✓ Student record deleted successfully!\n";
        } else {
            cout << "\nDeletion cancelled.\n";
        }
    }

    // Display statistics
    void displayStatistics() {
        if (students.empty()) {
            cout << "\nNo student records found!\n";
            return;
        }

        float totalMarks = 0;
        float highestMarks = students[0].getMarks();
        float lowestMarks = students[0].getMarks();
        string topStudent = students[0].getName();
        
        for (const auto &student : students) {
            float marks = student.getMarks();
            totalMarks += marks;
            
            if (marks > highestMarks) {
                highestMarks = marks;
                topStudent = student.getName();
            }
            if (marks < lowestMarks) {
                lowestMarks = marks;
            }
        }

        float averageMarks = totalMarks / students.size();

        cout << "\n--- Student Statistics ---\n";
        cout << string(50, '=') << endl;
        cout << "Total Students    : " << students.size() << endl;
        cout << "Average Marks     : " << fixed << setprecision(2) << averageMarks << endl;
        cout << "Highest Marks     : " << highestMarks << endl;
        cout << "Lowest Marks      : " << lowestMarks << endl;
        cout << "Top Student       : " << topStudent << endl;
        cout << string(50, '=') << endl;
    }

    // Display students by course
    void displayByCourse() {
        if (students.empty()) {
            cout << "\nNo student records found!\n";
            return;
        }

        string course;
        cin.ignore();
        cout << "\nEnter Course Name: ";
        getline(cin, course);

        vector<Student> filteredStudents;
        for (const auto &student : students) {
            if (student.getCourse() == course) {
                filteredStudents.push_back(student);
            }
        }

        if (filteredStudents.empty()) {
            cout << "\nNo students found in course: " << course << endl;
            return;
        }

        cout << "\n--- Students in " << course << " ---\n";
        cout << string(110, '=') << endl;
        cout << left << setw(12) << "Roll No" 
             << setw(25) << "Name" 
             << setw(20) << "Course" 
             << setw(10) << "Marks" 
             << setw(30) << "Email" << endl;
        cout << string(110, '-') << endl;

        for (const auto &student : filteredStudents) {
            student.displayData();
        }
        cout << string(110, '=') << endl;
        cout << "Total Students in " << course << ": " << filteredStudents.size() << endl;
    }
};

// Display menu
void displayMenu() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════╗\n";
    cout << "║   STUDENT MANAGEMENT SYSTEM                ║\n";
    cout << "╚════════════════════════════════════════════╝\n";
    cout << "  1. Add New Student\n";
    cout << "  2. Display All Students\n";
    cout << "  3. Search Student\n";
    cout << "  4. Update Student Record\n";
    cout << "  5. Delete Student Record\n";
    cout << "  6. Display Statistics\n";
    cout << "  7. Display Students by Course\n";
    cout << "  8. Exit\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    StudentManagementSystem sms;
    int choice;

    cout << "\n";
    cout << "═══════════════════════════════════════════════\n";
    cout << "   Welcome to Student Management System!       \n";
    cout << "═══════════════════════════════════════════════\n";

    while (true) {
        displayMenu();
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayAllStudents();
                break;
            case 3:
                sms.searchStudent();
                break;
            case 4:
                sms.updateStudent();
                break;
            case 5:
                sms.deleteStudent();
                break;
            case 6:
                sms.displayStatistics();
                break;
            case 7:
                sms.displayByCourse();
                break;
            case 8:
                cout << "\n═══════════════════════════════════════\n";
                cout << "   Thank you for using the system!    \n";
                cout << "   Goodbye!                           \n";
                cout << "═══════════════════════════════════════\n\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please enter a number between 1-8.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
