#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    float gpa;
};

// Function to load data from file
vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file("students.txt");

    Student s;
    while (file >> s.id >> s.name >> s.gpa) {
        students.push_back(s);
    }

    file.close();
    return students;
}

// Function to save data back to file
void saveStudents(vector<Student>& students) {
    ofstream file("students.txt");

    for (auto s : students) {
        file << s.id << " " << s.name << " " << s.gpa << endl;
    }

    file.close();
}

// Search function
void searchStudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "Found: " << s.name << " " << s.gpa << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

// Update function
void updateStudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin >> s.name;
            cout << "Enter new GPA: ";
            cin >> s.gpa;

            cout << "Updated successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

int main() {
    vector<Student> students = loadStudents();

    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Search Student\n";
        cout << "2. Update Student\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            searchStudent(students);
            break;
        case 2:
            updateStudent(students);
            saveStudents(students); // Save after update
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
