
#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int patientId;
    string patientName;
    static int activePatients;

public:
    Patient(int id, const string& name) : patientId(id), patientName(name) {
        activePatients++;
    }

    ~Patient() {
        activePatients--; 
    }

    static void showActivePatients() {
        cout << "Currently active patients: " << activePatients << endl;
    }
    void display() const {
        cout << "Patient ID: " << patientId << ", Name: " << patientName << endl;
    }
};

int Patient::activePatients = 0;

int main() {
    cout << "At start:" << endl;
    Patient::showActivePatients();

    Patient p1(1, "Rahul");
    Patient p2(2, "Anita");

    cout << "\nAfter creating two patients:" << endl;
    Patient::showActivePatients();
    {
        Patient p3(3, "Vikram");
        cout << "\nInside local block (p3 created):" << endl;
        Patient::showActivePatients();
    }

    cout << "\nAfter local block (p3 destroyed):" << endl;
    Patient::showActivePatients();

    return 0;
}
