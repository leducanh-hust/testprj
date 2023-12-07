#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
protected:
    string fullName;
    string cccd;
    int birthYear;

public:
    Person(string name, string id, int year) : fullName(name), cccd(id), birthYear(year) {}

    virtual void readInfo() {
        cin.ignore();
        cout << "Enter full name: ";
        getline(cin, fullName);
        cout << "Enter CCCD: ";
        cin >> cccd;
        cout << "Enter birth year: ";
        cin >> birthYear;
        cin.ignore();
    }

    virtual void displayInfo() const {
        cout << "Full Name: " << fullName << "\nCCCD: " << cccd << "\nBirth Year: " << birthYear << endl;
    }

    virtual string getFullName() const {
        return fullName;
    }

    virtual string getCCCD() const {
        return cccd;
    }
};

class Student : public Person {
private:
    string studentID;
    string major;
    string school;
    float cpa;

public:
    Student(string id, string m, string s, float gpa) : studentID(id), major(m), school(s), cpa(gpa), Person("", "", 0) {}

    void readInfo() override {
        Person::readInfo();
        cout << "Enter Student ID: ";
        cin >> studentID;
        cin.ignore();
        cout << "Enter Major: ";
        getline(cin, major);
        cout << "Enter School: ";
        cin >> school;
        cout << "Enter CPA: ";
        cin >> cpa;
        cin.ignore();
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Student ID: " << studentID << "\nMajor: " << major << "\nSchool: " << school << "\nCPA: " << cpa << endl;
    }

    float getCPA() const {
        return cpa;
    }

    string getStudentID() const {
        return studentID;
    }

    string getMajor() const {
        return major;
    }

    string getSchool() const {
        return school;
    }

};

class Staff : public Person {
private:
    string staffID;
    int staffType;
    string department;
    string expertise;
    int startYear;

public:
    Staff(string id, int type, string dep, string exp, int year) : staffID(id), staffType(type), department(dep), expertise(exp), startYear(year), Person("", "", 0) {}

    void readInfo() override {
        Person::readInfo();
        cout << "Enter Staff ID: ";
        cin >> staffID;
        cout << "Enter Staff Type (1: Lecturer, 2: Staff): ";
        cin >> staffType;
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Expertise: ";
        cin >> expertise;
        cout << "Enter Start Year: ";
        cin >> startYear;
        cin.ignore();
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Staff ID: " << staffID << "\nStaff Type: " << staffType << "\nDepartment: " << department << "\nExpertise: " << expertise << "\nStart Year: " << startYear << endl;
    }

    int getStartYear() const {
        return startYear;
    }

    virtual string getStaffID() const {
        return staffID;
    }

    virtual string getDepartment() const {
        return department;
    }

    virtual string getExpertise() const {
        return expertise;
    }

    virtual int getStaffType() const {
        return staffType;
    }
};

class Lecturer : public Staff {
private:
    string departmentSpecialization;
    string taughtSubject;

public:
    Lecturer(string depSpec, string subject) : departmentSpecialization(depSpec), taughtSubject(subject), Staff("", 1, "", "", 0) {}

    void readInfo() override {
        Staff::readInfo();
        cout << "Enter Department Specialization: ";
        cin >> departmentSpecialization;
        cout << "Enter Taught Subject: ";
        cin >> taughtSubject;
        cin.ignore();
    }

    string getTaughtSubject() const {
        return taughtSubject;
    }

    void displayInfo() const override {
        Staff::displayInfo();
        cout << "Department Specialization: " << departmentSpecialization << "\nTaught Subject: " << taughtSubject << endl;
    }

    string getDepartmentSpecialization() const {
        return departmentSpecialization;
    }
};

void displayStudentList(const vector<Student>& students) {
    cout << "Student List:\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "|   Student ID   |   Full Name   |   Major   |   School   |   CPA   |\n";
    cout << "--------------------------------------------------------------------\n";
    for (const auto& student : students) {
        cout << "|   " << student.getStudentID() << "   |   " << student.getFullName() << "   |   " << student.getMajor() << "   |   " << student.getSchool() << "   |   " << student.getCPA() << "   |\n";
    }
    cout << "--------------------------------------------------------------------\n";
}

void displayLecturerList(const vector<Lecturer>& lecturers) {
    cout << "Lecturer List:\n";
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "|   Staff ID   |   Full Name   |   Department   |   Expertise   |   Start Year   |   Department Specialization   |   Taught Subject   |\n";
    cout << "---------------------------------------------------------------------------------------------\n";
    for (const auto& lecturer : lecturers) {
        cout << "|   " << lecturer.getStaffID() << "   |   " << lecturer.getFullName() << "   |   " << lecturer.getDepartment() << "   |   " << lecturer.getExpertise() << "   |   " << lecturer.getStartYear() << "   |   " << lecturer.getDepartmentSpecialization() << "   |   " << lecturer.getTaughtSubject() << "   |\n";
    }
    cout << "---------------------------------------------------------------------------------------------\n";
}

int main() {
    vector<Student> studentList;
    vector<Lecturer> lecturerList;

    // Nhập thông tin sinh viên và giảng viên
    // for (int i = 0; i < 5; ++i) {
    //     cout << "Student " << i + 1 << ":\n";
    //     Student student("", "", "", 0.0);
        
    //     student.readInfo();
    //     studentList.push_back(student);

    //     Lecturer lecturer("", "");
    //     lecturer.readInfo();
    //     lecturerList.push_back(lecturer);
    // }

    Student student1("20213687", "IoT", "SEEE", 3.5);
    studentList.push_back(student1);
    Student student2("20213688", "IoT", "SEEE", 3.1);
    studentList.push_back(student2);
    Student student3("20213689", "IoT", "SEEE", 2.96);
    studentList.push_back(student3);
    Student student4("20213690", "IoT", "SEEE", 2.87);
    studentList.push_back(student4);
    Student student5("20213691", "IoT", "SEEE", 2.97);
    studentList.push_back(student5);
    Student student6("20213692", "IoT", "SEEE", 2.5);
    studentList.push_back(student6);
    Student student7("20213696", "IoT", "SEEE", 2.4);
    studentList.push_back(student7);
    Student student8("20213694", "IoT", "SEEE", 2.2);
    studentList.push_back(student8);
    Student student9("20213693", "IoT", "SEEE", 2.1);
    studentList.push_back(student9);
    Student student10("20213695", "IoT", "SEEE", 2.8);
    studentList.push_back(student10);



    // Hiển thị danh sách sinh viên
    displayStudentList(studentList);

    // Sắp xếp theo mã sinh viên và hiển thị lại
    sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
        return a.getStudentID() < b.getStudentID();
    });

    displayStudentList(studentList);

    // Sắp xếp theo CPA và hiển thị lại
    sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
        return a.getCPA() > b.getCPA();
    });

    displayStudentList(studentList);

    cout << endl;
    cout << endl;

    // Hiển thị sinh viên có CPA cao nhất
    cout << "Student with the highest CPA:\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "|   Student ID   |   Full Name   |   Major   |   School   |   CPA   |\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "|   " << studentList[0].getStudentID() << "   |   " << studentList[0].getFullName() << "   |   " << studentList[0].getMajor() << "   |   " << studentList[0].getSchool() << "   |   " << studentList[0].getCPA() << "   |\n";
    cout << "--------------------------------------------------------------------\n";


    // Nhập thông tin giảng viên
    
    // for(int i = 0; i < 2; ++i)
    // {
    //     cout << "Lecturer " << i + 1 << ":\n";
    //     Lecturer lecturer("", "");
    //     lecturer.readInfo();
    //     lecturerList.push_back(lecturer);
    //     cout << endl;
    // }
    
    // // Hiển thị danh sách giảng viên
    // displayLecturerList(lecturerList);

    // // Tìm giảng viên có số năm công tác lớn nhất
    // auto maxExperienceLecturer = max_element(lecturerList.begin(), lecturerList.end(), [](const Lecturer& a, const Lecturer& b) {
    //     return a.getStartYear() < b.getStartYear();
    // });

    // cout << "Lecturer with the most years of experience:\n";
    // cout << "---------------------------------------------------------------------------------------------\n";
    // cout << "|   Staff ID   |   Full Name   |   Department   |   Expertise   |   Start Year   |   Department Specialization   |   Taught Subject   |\n";
    // cout << "---------------------------------------------------------------------------------------------\n";
    // cout << "|   " << maxExperienceLecturer->getStaffID() << "   |   " << maxExperienceLecturer->getFullName() << "   |   " << maxExperienceLecturer->getDepartment() << "   |   " << maxExperienceLecturer->getExpertise() << "   |   " << maxExperienceLecturer->getStartYear() << "   |   " << maxExperienceLecturer->getDepartmentSpecialization() << "   |   " << maxExperienceLecturer->getTaughtSubject() << "   |\n";
    // cout << "---------------------------------------------------------------------------------------------\n";


    return 0;
}
