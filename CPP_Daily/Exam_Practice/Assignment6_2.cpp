#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}

    Employee(int id, double salary) : id(id), salary(salary) {cout<<"Employee(int id, double salary)"<<endl;}

    void setId(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }

    double getSalary() {
        return salary;
    }

    virtual void accept() {
        cout << "Enter Id: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display() {
        cout << "Employee Id: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

// ---------------- Manager ----------------
class Manager : virtual public Employee {
protected:
    double bonus;

public:
    Manager() : bonus(0.0) {}

    Manager(int id, double salary, double bonus)
        : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus) {
        this->bonus = bonus;
    }

    double getBonus() {
        return bonus;
    }

    void acceptManager() {
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void displayManager() {
        cout << "Bonus: " << bonus << endl;
    }

    void accept() override {
        Employee::accept();
        acceptManager();
    }

    void display() override {
        Employee::display();
        displayManager();
    }
};

// ---------------- Salesman ----------------
class Salesman : virtual public Employee {
protected:
    double commission;

public:
    Salesman() : commission(0.0) {}

    Salesman(int id, double salary, double commission)
        : Employee(id, salary), commission(commission) {}

    void setCommission(double commission) {
        this->commission = commission;
    }

    double getCommission() {
        return commission;
    }

    void acceptSalesman() {
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void displaySalesman() {
        cout << "Commission: " << commission << endl;
    }

    void accept() override {
        Employee::accept();
        acceptSalesman();
    }

    void display() override {
        Employee::display();
        displaySalesman();
    }
};

// ---------------- SalesManager ----------------
class SalesManager : public Manager, public Salesman {
public:
    SalesManager() {}

    SalesManager(int id, double salary, double bonus, double commission): Employee(id, salary) 
    {
        setBonus(bonus);
        setCommission(commission);
    }

    void accept()  {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display(){
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};


int main() {
    cout << "Testing Employee:" << endl;
    Employee e1;
    e1.accept();
    e1.display();

    cout << "\nTesting Manager:" << endl;
    Manager m1;
    m1.accept();
    m1.display();

    cout << "\nTesting Salesman:" << endl;
    Salesman s1;
    s1.accept();
    s1.display();

    cout << "\nTesting SalesManager:" << endl;
    SalesManager sm1;
    sm1.accept();
    sm1.display();

    return 0;
}
