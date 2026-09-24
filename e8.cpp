#include <iostream>
#include <string>
using namespace std;

class Product {
    int productId;
    string productName;
    double price;

public:
    Product(int id = 0, string name = "", double p = 0.0) {
        productId = id;
        productName = name;
        price = p;
    }

    void getData() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Price: ";
        cin >> price;
    }

    double calculatePrice() {
        return price;
    }

    double calculatePrice(double discount) {
        return price - (price * discount / 100);
    }

    double calculatePrice(double discount, double deliveryCharge) {
        return price - (price * discount / 100) + deliveryCharge;
    }

    void display() {
        cout << "\nProduct ID   : " << productId << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Price        : " << price << endl;
        cout << "Original Price                  : "
             << calculatePrice() << endl;
        cout << "Price after 10% Discount        : "
             << calculatePrice(10) << endl;
        cout << "Price after Discount + Delivery : "
             << calculatePrice(10, 50) << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    Product *products = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << endl;
        products[i].getData();
    }

    cout << "\n----- PRODUCT DETAILS -----\n";

    for (int i = 0; i < n; i++) {
        products[i].display();
    }

    delete[] products;

    return 0;
}
