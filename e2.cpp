class BankAccount {
private:
    int accountNumber;
    string customerName;
    double balance;

public:
    BankAccount(int accNo, const string& name, double bal)
        : accountNumber(accNo), customerName(name), balance(bal) {}

    friend void compareBalance(const BankAccount& acc1, const BankAccount& acc2);
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: " << balance << endl;
    }
};
void compareBalance(const BankAccount& acc1, const BankAccount& acc2) {
    if (acc1.balance > acc2.balance) {
        cout << "higher balance:" << endl;
        acc1.display();
    } else if (acc2.balance > acc1.balance) {
        cout << "higher balance:" << endl;
        acc2.display();
    } else {
        cout << "equal balance:" << endl;
        acc1.display();
        acc2.display();
    }
}
