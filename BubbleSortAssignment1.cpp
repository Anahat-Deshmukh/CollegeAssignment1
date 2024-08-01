#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    int roll_no;
    string name;
    float sgpa;

    Student(int r, string n, float s) : roll_no(r), name(n), sgpa(s) {}
};

void bubbleSortByRollNo(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void printStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Roll No: " << student.roll_no << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
    }
}

int main() {
    vector<Student> students = {
        {2301, "Harry", 9.1},
        {2305, "Hermoine", 8.5},
        {2310, "Anahat", 8.9},
        {2345, "Von", 5.3},
        {2320, "Ron", 4.6},
        {2315, "Steve", 5.8},
        {2340, "Kabir", 7.2},
        {2335, "Hari-Om", 8.5},
        {2330, "Genelia", 7.4},
        {2325, "John Cena", 8.3}
    };

    bubbleSortByRollNo(students);

    cout << "Sorted by Roll Number (Bubble Sort):" << endl;
    printStudents(students);

    return 0;
}
