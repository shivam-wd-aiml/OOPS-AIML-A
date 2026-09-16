#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeId;
    string name;
    double salary;

public:
    Employee() : employeeId(0), name("Unknown"), salary(0.0) {}
    Employee(int id, const string& n, double s)
        : employeeId(id), name(n), salary(s) {}
    Employee(const Employee& other)
        : employeeId(other.employeeId), name(other.name), salary(other.salary) {}


    void display() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    void updateSalary(double newSalary) {
        salary = newSalary;
    }
};

int main() {
    const Employee e1(101, "Rahul", 50000.0);
    cout << "Const Employee object details:" << endl;
    e1.display();
    Employee e2(e1);
    cout << "\nCopied Employee object details:" << endl;
    e2.display();
}
