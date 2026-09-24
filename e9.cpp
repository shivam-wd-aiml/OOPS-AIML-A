#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int employeeId;
    string name;
    double basicSalary;

public:
    Employee(int id, string n, double salary) {
        employeeId = id;
        name = n;
        basicSalary = salary;
    }

    virtual double calculateSalary() = 0;

    virtual void display() {
        cout << "\nEmployee ID : " << employeeId << endl;
        cout << "Name        : " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
    }

    virtual ~Employee() {}
};

class Doctor : public Employee {
    double consultationAllowance;

public:
    Doctor(int id, string n, double salary, double allowance)
        : Employee(id, n, salary) {
        consultationAllowance = allowance;
    }

    double calculateSalary() override {
        return basicSalary + consultationAllowance;
    }

    void display() override {
        Employee::display();
        cout << "Consultation Allowance: " << consultationAllowance << endl;
        cout << "Total Salary          : " << calculateSalary() << endl;
    }
};

class Nurse : public Employee {
    double nightShiftAllowance;

public:
    Nurse(int id, string n, double salary, double allowance)
        : Employee(id, n, salary) {
        nightShiftAllowance = allowance;
    }

    double calculateSalary() override {
        return basicSalary + nightShiftAllowance;
    }

    void display() override {
        Employee::display();
        cout << "Night Shift Allowance: " << nightShiftAllowance << endl;
        cout << "Total Salary         : " << calculateSalary() << endl;
    }
};

int main() {
    Employee* e1 = new Doctor(101, "Aman", 50000, 10000);
    Employee* e2 = new Nurse(201, "Riya", 30000, 5000);

    cout << "Doctor Details:" << endl;
    e1->display();

    cout << "\nNurse Details:" << endl;
    e2->display();

    delete e1;
    delete e2;

    return 0;
}
