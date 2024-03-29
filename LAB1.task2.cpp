#include <iostream>
#include <string>

using namespace std;

const int max_students = 40;

struct Students {
    string name;
    string reg_no; // Changed to string
    int age;
};

struct course {
    string course_name, course_code;
};

struct grade {
    int mark;
    char Grade;
};

void addStudents(Students students[], int& numStudents); // Changed function name
void editStudent(Students students[], int numStudents);
void addMarks(Students students[], int numStudents);
char calculateGrade(int mark);

int main() {
    Students students[max_students];
    int numStudents = 0;
    int switc;
    cout << "Enter number btn 1 - 3";
    cin >> switc;

    switch (switc) {
        case 1: {
            addStudents(students, numStudents); // Corrected argument
            break;
        }
        case 2: {
            editStudent(students, numStudents);
            break;
        }
        case 3: {
            addMarks(students, numStudents);
            break;
        }
        default:
            break;
    }

    return 0;
}

void addStudents(Students students[], int& numStudents) {
    if (numStudents < max_students) {
        Students newStudent;
        cout << "Enter name" << endl;
        cin.ignore(); // Ignore newline character
        getline(cin, newStudent.name);
        cout << "Enter age" << endl;
        cin >> newStudent.age;
        cout << "Enter registration number" << endl;
        cin >> newStudent.reg_no;

        course Course;
        cout << "Enter course name:";
        cin >> Course.course_name;
        cout << "\nEnter course code: ";
        cin >> Course.course_code;

        students[numStudents++] = newStudent;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

void editStudent(Students students[], int numStudents) {
    string regNum;
    cout << "Enter registration number of student to edit: ";
    cin >> regNum;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_no == regNum) {
            cout << "Enter new name: ";
            cin.ignore(); // Ignore newline character
            getline(cin, students[i].name);
            cout << "Enter new age: ";
            cin >> students[i].age;
            cout << "Student details updated successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void addMarks(Students students[], int numStudents) {
    string regNum;
    cout << "Enter registration number of student to edit: ";
    cin >> regNum;
    grade grade1;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_no == regNum) {
            cout << "Enter mark" << endl;
            cin >> grade1.mark;
            // Print calculated grade
            cout << "Grade: " << calculateGrade(grade1.mark) << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

char calculateGrade(int mark) {
    if (mark > 69) {
        return 'A';
    } else if (mark > 59) {
        return 'B';
    } else if (mark > 49) {
        return 'C';
    } else if (mark > 39) { // Changed condition to mark > 39
        return 'D';
    } else {
        return 'E';
    }
}
