#include <iostream>
#include <string>
using namespace std;

class ResultAnalyzer; 

class StudentResult {
private:
    int rollNo;
    string name;
    int marks[3];   
    static int totalStudents;

public:

    StudentResult(int r, const string& n, int m1, int m2, int m3)
        : rollNo(r), name(n) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        totalStudents++;   
    }

    ~StudentResult() {
        cout << "Destructor called for student: " << name << endl;
        totalStudents--;  
    }
    friend class ResultAnalyzer;
    static void showTotalStudents() {
        cout << "Currently active StudentResult objects: " << totalStudents << endl;
    }
};
int StudentResult::totalStudents = 0;
class ResultAnalyzer {
public:
    void analyze(const StudentResult& s) {
        int total = s.marks[0] + s.marks[1] + s.marks[2];
        double percentage = total / 3.0;

        cout << "\n--- Result Analysis ---" << endl;
        cout << "Roll No: " << s.rollNo << endl;
        cout << "Name: " << s.name << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Result: " << (percentage >= 40 ? "Pass" : "Fail") << endl;
    }
};

int main() {
    cout << "At start:" << endl;
    StudentResult::showTotalStudents();

    {
        StudentResult s1(101, "Rahul", 80, 75, 90);
        StudentResult s2(102, "Anita", 40, 35, 50);

        cout << "\nAfter creating two students:" << endl;
        StudentResult::showTotalStudents();

        ResultAnalyzer analyzer;
        analyzer.analyze(s1);
        analyzer.analyze(s2);
    } 

    cout << "\nAfter local block:" << endl;
    StudentResult::showTotalStudents();

    return 0;
}
