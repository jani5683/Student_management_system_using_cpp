#include <iostream>
#include <string>
using namespace std;

class Student {
    int id;
    string name;
    string grade;
    string classSection;

public:
    void createStudent() {
        cout << "\tEnter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "\tEnter Student Name: ";
        getline(cin, name);
        cout << "\tEnter Class Section: ";
        getline(cin, classSection);
        cout << "\tEnter Grade: ";
        getline(cin, grade);
        cout << "\tStudent record created successfully!\n";
    }

    void displayStudent() {
        cout << "\n\tStudent ID: " << id;
        cout << "\n\tName: " << name;
        cout << "\n\tClass Section: " << classSection;
        cout << "\n\tGrade: " << grade << endl;
    }

    int getStudentID() {
        return id;
    }

    void modifyStudent() {
        cout << "\tEnter new Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\tEnter new Class Section: ";
        getline(cin, classSection);
        cout << "\tEnter new Grade: ";
        getline(cin, grade);
        cout << "\tStudent record updated successfully!\n";
    }
};

class StudentManagementSystem {
    Student students[100]; // Supports up to 100 students.
    int studentCount = 0;

public:
    void addStudent() {
        if (studentCount < 100) {
            students[studentCount].createStudent();
            studentCount++;
        } else {
            cout << "\tStudent list is full.\n";
        }
    }

    void displayAllStudents() {
        if (studentCount == 0) {
            cout << "\tNo student records available.\n";
        } else {
            for (int i = 0; i < studentCount; i++) {
                students[i].displayStudent();
            }
        }
    }

    void searchStudent() {
        int id;
        cout << "\tEnter Student ID to search: ";
        cin >> id;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getStudentID() == id) {
                students[i].displayStudent();
                return;
            }
        }
        cout << "\tStudent with ID " << id << " not found.\n";
    }

    void modifyStudent() {
        int id;
        cout << "\tEnter Student ID to modify: ";
        cin >> id;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getStudentID() == id) {
                students[i].modifyStudent();
                return;
            }
        }
        cout << "\tStudent with ID " << id << " not found.\n";
    }

    void deleteStudent() {
        int id;
        cout << "\tEnter Student ID to delete: ";
        cin >> id;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getStudentID() == id) {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "\tStudent record deleted successfully!\n";
                return;
            }
        }
        cout << "\tStudent with ID " << id << " not found.\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n\tStudent Management System\n";
            cout << "\t1. Add Student\n";
            cout << "\t2. Display All Students\n";
            cout << "\t3. Search Student\n";
            cout << "\t4. Modify Student\n";
            cout << "\t5. Delete Student\n";
            cout << "\t6. Exit\n";
            cout << "\tEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    displayAllStudents();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    modifyStudent();
                    break;
                case 5:
                    deleteStudent();
                    break;
                case 6:
                    cout << "\tExiting system...\n";
                    break;
                default:
                    cout << "\tInvalid choice. Try again.\n";
                    break;
            }
        } while (choice != 6);
    }
};

int main() {
    StudentManagementSystem sms;
    sms.menu();
    return 0;
}
