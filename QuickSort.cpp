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

int partition(vector<Student>& students, int low, int high) {
    float pivot = students[high].sgpa;
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (students[j].sgpa > pivot) {
            ++i;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSortBySGPA(vector<Student>& students, int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);
        quickSortBySGPA(students, low, pi - 1);
        quickSortBySGPA(students, pi + 1, high);
    }
}

void printStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Roll No: " << student.roll_no << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
    }
}

int main() {
    vector<Student> students = {
        {101, "Alice", 9.1},
        {103, "Bob", 8.5},
        {102, "Charlie", 8.9},
        // Add more students as needed
    };

    quickSortBySGPA(students, 0, students.size() - 1);

    cout << "Top 10 Toppers (Quick Sort):" << endl;
    for (int i = 0; i < min(10, (int)students.size()); ++i) {
        cout << students[i] << endl;
    }

    return 0;
}
