#include <iostream>
#include <string>
using namespace std;

class University {
private:
    string universityName;

public:
    University(const string& name) : universityName(name) {}
    class Department {
    private:
        string departmentName;
        int studentCount;

    public:
        Department(const string& deptName, int count)
            : departmentName(deptName), studentCount(count) {}
        void showDetails(const University& uni) const {
            cout << "University: " << uni.universityName << endl;
            cout << "Department: " << departmentName << endl;
            cout << "Student Count: " << studentCount << endl;
        }
    };
};

int main() {
    University u("ABES Engineering College");
    University::Department d("Computer Science", 120);
    d.showDetails(u);

    return 0;
}
