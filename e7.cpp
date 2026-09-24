#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    double cgpa;

public:
    class Address {
    private:
        string city;
        string state;

    public:
        Address(string city = "Not Assigned", string state = "Not Assigned") {
            this->city = city;
            this->state = state;
        }

        void displayAddress() {
            cout << "City  : " << city << endl;
            cout << "State : " << state << endl;
        }
    };

    Address address;
    Student(int rollNo, string name)
        : rollNo(rollNo), name(name), cgpa(0.0) {}

    Student(int rollNo, string name, double cgpa)
        : rollNo(rollNo), name(name), cgpa(cgpa) {}

    void updateCGPA(double cgpa) {
        this->cgpa = cgpa;
    }

    void setAddress(string city, string state) {
        address = Address(city, state);
    }

    void displayInfo() {
        cout << "\nRoll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "CGPA    : " << cgpa << endl;
        address.displayAddress();
    }
};

int main() {
    Student students[5] = {
        Student(101, "Aman"),
        Student(102, "Riya", 8.5),
        Student(103, "Karan"),
        Student(104, "Priya", 9.1),
        Student(105, "Rahul", 7.8)
    };

    students[0].setAddress("Delhi", "Delhi");
    students[1].setAddress("Noida", "Uttar Pradesh");
    students[2].setAddress("Lucknow", "Uttar Pradesh");
    students[3].setAddress("Jaipur", "Rajasthan");
    students[4].setAddress("Chandigarh", "Punjab");

    students[0].updateCGPA(8.2);
    students[2].updateCGPA(7.9);


    cout << "===== STUDENT DETAILS =====" << endl;

    for (int i = 0; i < 5; i++) {
        students[i].displayInfo();
    }

    return 0;
}
