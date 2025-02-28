#include <bits/stdc++.h>
using namespace std;

struct Student {
    char name[30];
    char stuClass[10];
    float mMath;
    float mPhysical;
};

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Nhập tên học sinh: ";
    cin.ignore();
    cin.getline(s.name, 30);
    cout << "Nhập lớp: ";
    cin.getline(s.stuClass, 10);
    cout << "Nhập điểm Toán: ";
    cin >> s.mMath;
    cout << "Nhập điểm Lý: ";
    cin >> s.mPhysical;
    students.push_back(s);
    cout << "Thêm học sinh thành công." << endl;
}

void searchStudentByName(const vector<Student>& students) {
    char searchName[30];
    cout << "Nhập tên học sinh cần tìm: ";
    cin.ignore();
    cin.getline(searchName, 30);

    bool found = false;
    for (const auto& student : students) {
        if (strcmp(student.name, searchName) == 0) {
            cout << "Tìm thấy học sinh:" << endl;
            cout << "Tên: " << student.name << endl;
            cout << "Lớp: " << student.stuClass << endl;
            cout << "Điểm Toán: " << student.mMath << endl;
            cout << "Điểm Lý: " << student.mPhysical << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Không tìm thấy học sinh." << endl;
}

void editStudentClass(vector<Student>& students) {
    char searchName[30];
    char newClass[10];
    cout << "Nhập tên học sinh cần sửa: ";
    cin.ignore();
    cin.getline(searchName, 30);

    bool found = false;
    for (auto& student : students) {
        if (strcmp(student.name, searchName) == 0) {
            cout << "Nhập lớp mới: ";
            cin.getline(newClass, 10);
            strcpy(student.stuClass, newClass);
            cout << "Cập nhật lớp thành công." << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Không tìm thấy học sinh." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Thêm học sinh mới" << endl;
        cout << "2. Tìm kiếm học sinh theo tên" << endl;
        cout << "3. Tìm kiếm và sửa lớp học sinh" << endl;
        cout << "4. Thoát" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                searchStudentByName(students);
                break;
            case 3:
                editStudentClass(students);
                break;
            case 4:
                cout << "Đang thoát chương trình..." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng thử lại." << endl;
        }
    } while (choice != 4);

    return 0;
}