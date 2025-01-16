#include <iostream>
#include <string>
using namespace std;

struct student {
    int studentID;
    string name;
    int age;
    string course;
    float grade;
};

string toLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void addStudent(student details[], int &studentsNum, int maxStudents) {
    if (studentsNum >= maxStudents) {
        cout << "Database is full!" << endl;
        return;
    }

    cout << "Enter student ID: ";
    cin >> details[studentsNum].studentID;
    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, details[studentsNum].name);

    cout << "Enter student age: ";
    cin >> details[studentsNum].age;
    cin.ignore();

    cout << "Enter student course: ";
    getline(cin, details[studentsNum].course);

    cout << "Enter student grade: ";
    cin >> details[studentsNum].grade;
    cin.ignore();

    studentsNum++;
    cout << "Student added successfully!" << endl;
}

void displayStudents(student details[], int studentsNum) {
    cout << "\nDisplaying all students:" << endl;
    for (int i = 0; i < studentsNum; i++) {
        cout << "\tStudent ID: " << details[i].studentID << endl;
        cout << "\tName: " << details[i].name << endl;
        cout << "\tAge: " << details[i].age << endl;
        cout << "\tCourse: " << details[i].course << endl;
        cout << "\tGrade: " << details[i].grade << endl;
        cout << "----------------------" << endl;
    }
}

void updateRecord(student details[], int studentsNum, int searchID) {
    bool found = false;
    for (int i = 0; i < studentsNum; i++) {
        if (details[i].studentID == searchID) {
            cout << "Enter new details for student " << details[i].name << ":" << endl;

            cout << "Enter new name: ";
            getline(cin, details[i].name);

            cout << "Enter new age: ";
            cin >> details[i].age;
            cin.ignore();

            cout << "Enter new course: ";
            getline(cin, details[i].course);

            cout << "Enter new grade: ";
            cin >> details[i].grade;
            cin.ignore();

            cout << "Record updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << searchID << " not found!" << endl;
    }
}

void deleteRecord(student details[], int &studentsNum, int searchID) {
    bool found = false;
    for (int i = 0; i < studentsNum; i++) {
        if (details[i].studentID == searchID) {
            for (int j = i; j < studentsNum - 1; j++) {
                details[j] = details[j + 1];
            }
            studentsNum--;
            cout << "Record deleted successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << searchID << " not found!" << endl;
    }
}

void sortByID(student details[], int studentsNum) {
    for (int i = 0; i < studentsNum - 1; i++) {
        for (int j = i + 1; j < studentsNum; j++) {
            if (details[i].studentID > details[j].studentID) {
                swap(details[i], details[j]);
            }
        }
    }
    cout << "Students sorted by ID." << endl;
}

void sortByName(student details[], int studentsNum) {
    for (int i = 0; i < studentsNum - 1; i++) {
        for (int j = i + 1; j < studentsNum; j++) {
            if (details[i].name > details[j].name) {
                swap(details[i], details[j]);
            }
        }
    }
    cout << "Students sorted by name." << endl;
}

void calculateAverageGrade(student details[], int studentsNum) {
    if (studentsNum == 0) {
        cout << "No students in the database." << endl;
        return;
    }

    float totalGrades = 0;
    for (int i = 0; i < studentsNum; i++) {
        totalGrades += details[i].grade;
    }
    float averageGrade = totalGrades / studentsNum;
    cout << "The average grade of all students is: " << averageGrade << endl;
}

void findStudentsBelowGrade(student details[], int studentsNum, float gradeThreshold) {
    cout << "Students with grade below " << gradeThreshold << " are: " << endl;
    bool found = false;
    for (int i = 0; i < studentsNum; i++) {
        if (details[i].grade < gradeThreshold) {
            cout << "Student ID: " << details[i].studentID << " Name: " << details[i].name << " Grade: " << details[i].grade << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with grade below " << gradeThreshold << "." << endl;
    }
}

void findStudentsInCourse(student details[], int studentsNum, string courseName) {
    cout << "Students enrolled in " << courseName << " are: " << endl;
    bool found = false;
    for (int i = 0; i < studentsNum; i++) {
        if (toLower(details[i].course) == toLower(courseName)) {
            cout << "Student ID: " << details[i].studentID << " Name: " << details[i].name << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in the course " << courseName << "." << endl;
    }
}

void updateGrade(student details[], int studentsNum, int searchID) {
    bool found = false;
    for (int i = 0; i < studentsNum; i++) {
        if (details[i].studentID == searchID) {
            cout << "Enter the new grade for " << details[i].name << ": ";
            cin >> details[i].grade;
            cin.ignore();
            cout << "Grade updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << searchID << " not found!" << endl;
    }
}

void countStudents(int studentsNum) {
    cout << "Total number of students: " << studentsNum << endl;
}

void searchByAgeRange(student details[], int studentsNum, int minAge, int maxAge) {
    cout << "Students between " << minAge << " and " << maxAge << " years old:" << endl;
    bool found = false;
    for (int i = 0; i < studentsNum; i++) {
        if (details[i].age >= minAge && details[i].age <= maxAge) {
            cout << "Student ID: " << details[i].studentID << " Name: " << details[i].name << " Age: " << details[i].age << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in the age range " << minAge << " to " << maxAge << "." << endl;
    }
}

int main() {
    char y_n = 'y';
    int operation, operationsearch;
    int maxStudents = 20;
    student details[maxStudents];
    int studentsNum = 8;

    details[0] = {1, "John Doe", 20, "Math", 85.5};
    details[1] = {2, "Jane Smith", 21, "Science", 92.3};
    details[2] = {3, "Alice Brown", 22, "History", 78.4};
    details[3] = {4, "Bob Johnson", 19, "Math", 88.1};
    details[4] = {5, "Charlie Davis", 23, "Art", 91.5};
    details[5] = {6, "David Clark", 24, "Physics", 80.2};
    details[6] = {7, "Eve Evans", 21, "Biology", 93.7};
    details[7] = {8, "Frank Wilson", 20, "Math", 74.6};

    string courseName; // Declare the variable here so it's available in all cases
    float gradeStart;
    int minAge, maxAge;

    while (y_n == 'y') {
        cout << "\nMenu:" << endl;
        cout << "1. Add a new student." << endl;
        cout << "2. Update student record." << endl;
        cout << "3. Delete student record." << endl;
        cout << "4. Display all students." << endl;
        cout << "5. Sort students by ID." << endl;
        cout << "6. Sort students by name." << endl;
        cout << "7. Calculate average grade." << endl;
        cout << "8. Find students below a grade." << endl;
        cout << "9. Find students in a course." << endl;
        cout << "10. Update student grade." << endl;
        cout << "11. Count total number of students." << endl;
        cout << "12. Search students by age range." << endl;
        cout << "Enter operation number from (1-12): ";
        cin >> operation;
        cin.ignore();

        switch (operation) {
            case 1:
                addStudent(details, studentsNum, maxStudents);
                break;
            case 2:
                cout << "Enter student ID to update: ";
                cin >> operationsearch;
                cin.ignore();
                updateRecord(details, studentsNum, operationsearch);
                break;
            case 3:
                cout << "Enter student ID to delete: ";
                cin >> operationsearch;
                cin.ignore();
                deleteRecord(details, studentsNum, operationsearch);
                break;
            case 4:
                displayStudents(details, studentsNum);
                break;
            case 5:
                sortByID(details, studentsNum);
                break;
            case 6:
                sortByName(details, studentsNum);
                break;
            case 7:
                calculateAverageGrade(details, studentsNum);
                break;
            case 8:
                cout << "Enter grade: ";
                cin >> gradeStart;
                cin.ignore();
                findStudentsBelowGrade(details, studentsNum, gradeStart);
                break;
            case 9:
                cout << "Enter course name: ";
                getline(cin, courseName);  // Use the variable here
                findStudentsInCourse(details, studentsNum, courseName);
                break;
            case 10:
                cout << "Enter student ID to update grade: ";
                cin >> operationsearch;
                cin.ignore();
                updateGrade(details, studentsNum, operationsearch);
                break;
            case 11:
                countStudents(studentsNum);
                break;
            case 12:
                cout << "Enter minimum age: ";
                cin >> minAge;
                cout << "Enter maximum age: ";
                cin >> maxAge;
                cin.ignore();
                searchByAgeRange(details, studentsNum, minAge, maxAge);
                break;
            default:
                cout << "Invalid operation! Please try again." << endl;
                break;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> y_n;
    }

    return 0;
}
