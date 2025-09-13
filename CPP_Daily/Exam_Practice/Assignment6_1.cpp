#include<iostream>
using namespace std;

class Product {
    protected:
    int id;
    string title;
    float price;
    float discount_price;

    public:
    virtual void acceptProduct() {
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter title: ";
        cin>>title;
        cout<<"Enter price: ";
        cin>>price;
    }
    virtual void calculateDiscount() = 0;
    virtual void printProduct(){
        cout<<"Id: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Discounted Price: "<<discount_price<<endl;
    }

    float getDiscountedPrice(){
        return discount_price;
    }

    virtual ~Product() { } // virtual destructor to avoid memory leaks
};

class Book : public Product{
    private:
    string author;

    public:
    void acceptProduct(){
        Product::acceptProduct();
        cout<<"Enter author: ";
        cin>>author;
    }
    void calculateDiscount(){
        this->discount_price = this->price - (0.1f * this -> price);
    }

    void printProduct(){
        Product::printProduct();
        cout<<"Author: "<<author<<endl;
    }
};

class Tape:public Product{
    private:
    string artist;

    public:
    void acceptProduct(){
        Product::acceptProduct();
        cout<<"Enter artist: ";
        cin>>artist;
    }
    void calculateDiscount(){
        this->discount_price = this->price - (0.05f * this -> price);
    }

    void printProduct(){
        Product::printProduct();
        cout<<"Artist: "<<artist<<endl;
    }
};


int main(){
    Product* arr[3];   // array of product pointers
    int choice;

    cout << "Purchase 3 products (Book/Tape):" << endl;

    for (int i = 0; i < 3; i++) {
        // Menu directly here
        do {
            cout << "\n0. Exit" << endl;
            cout << "1. Book" << endl;
            cout << "2. Tape" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 0) {
                cout << "Exiting early..." << endl;
                return 0;
            }
        } while (choice < 1 || choice > 2);

        if (choice == 1)
            arr[i] = new Book();
        else
            arr[i] = new Tape();

        arr[i]->acceptProduct();
        arr[i]->calculateDiscount();
    }

    float totalBill = 0;
    cout << "\n----- Purchased Products -----" << endl;
    for (int i = 0; i < 3; i++) {
        arr[i]->printProduct();
        cout << "-------------------------" << endl;
        totalBill += arr[i]->getDiscountedPrice();
    }

    cout << "\nFinal Bill: " << totalBill << endl;

    // free memory
    for (int i = 0; i < 3; i++) {
        delete arr[i];
        arr[i] = NULL;
    }

    return 0;
}