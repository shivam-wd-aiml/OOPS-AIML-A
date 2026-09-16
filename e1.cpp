#include <bits/stdc++.h>
using namespace std;

class Product{
    private:
        int productId;
        string name;
        int price;
    public:
        Product(string s,int p,int pi){
            name=s;
            price=pi;
            productId=p;
        }
        Product compare(const Product &p1){
            if(this->price >= p1.price){
                return *this;
            }
            else{
                return p1;
            }
        }
        void display(){
            cout<<"Productid"<<productId<<'\n';
            cout<<"Name"<<name<<'\n';
            cout<<"Price"<<price<<'\n';
        }
};
int main() {
	Product p1("Laptop",101, 55000);
    Product p2("Smartphone",102, 30000);
    Product high= p1.compare(p2);
    high.display();

    return 0;
}
