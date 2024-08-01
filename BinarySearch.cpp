#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    int roll_no;
    string name;
    float sgpa;

    Student(int r, string n, float s) : roll_no(r), name(n), sgpa(s) {}
};

void insertionSortByName(vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; ++i) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            --j;
        }
        students[j + 1] = key;
    }
}

int binarySearchByName(const vector<Student>& students, const string& name) {
    int low = 0, high = students.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].name == name) {
            return mid;
        } else if (students[mid].name < name) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void printStudent(const Student& student) {
    cout << "Roll No: " << student.roll_no << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
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

    insertionSortByName(students);

    string name_to_search = "Anahat";
  cin>> name_to_search;
    int found_index = binarySearchByName(students, name_to_search);

    cout << "Student with name '" << name_to_search << "':" << endl;
    if (found_index != -1) {
        printStudent(students[found_index]);
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
