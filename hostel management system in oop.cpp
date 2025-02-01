#include <iostream>
using namespace std;
struct Student {
    int id;
    char name[50];
    int roomNumber;
};
Student hostel[100]; 
int studentCount = 0; 
void addStudent() {
    if (studentCount >= 100) {
        cout << "Hostel is full! Cannot add more students." << endl;
        return;
    }
    Student newStudent;

    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    cin.ignore();
    cout << "Enter Student Name: ";
    cin >> newStudent.name;
    cout << "Enter Room Number: ";
    cin >> newStudent.roomNumber;

    hostel[studentCount] = newStudent;
    studentCount++;

    cout << "Student added successfully!" << endl;
}
void displayStudents() {
    if (studentCount == 0) {
        cout << "No students in the hostel." << endl;
        return;
    }
    cout << "\nList of Students:" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << hostel[i].id << ", Name: " << hostel[i].name
             << ", Room Number: " << hostel[i].roomNumber << endl;
    }
}
void searchStudent() {
    if (studentCount == 0) {
        cout << "No students in the hostel." << endl;
        return;
    }
    int searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;
    for (int i = 0; i < studentCount; i++) {
        if (hostel[i].id == searchID) {
            cout << "Student found: " << endl;
            cout << "ID: " << hostel[i].id << ", Name: " << hostel[i].name
                 << ", Room Number: " << hostel[i].roomNumber << endl;
            return;
        }
    }
    cout << "Student with ID " << searchID << " not found." << endl;
}
int main() {
    int choice;
    do {
        cout << "\nHostel Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}