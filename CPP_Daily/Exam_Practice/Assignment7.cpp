#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    int id;
    double salary;
public:
    Employee() : id(0), salary(0.0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    virtual ~Employee() {}

    void setId(int id) {
         this->id = id;
    }
    int getId() { 
        return this->id; 
    }

    void setSalary(double salary) { 
        this->salary = salary;
     }
    double getSalary() {
         return this->salary;
    }

    virtual void accept() {
        cout << "Enter Id : ";
        cin >> id;
        cout << "Enter Salary : ";
        cin >> salary;
    }
    virtual void display() {
        cout << "Id : " << id << endl;
        cout << "Salary : " << salary << endl;
    }

    virtual string getType() = 0;
};

class Manager : virtual public Employee {
private:
    double bonus;
public:
    Manager() : bonus(0.0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus) { 
        this->bonus = bonus;
     }
    double getBonus() { 
        return this->bonus;
     }

    void accept() {
        Employee::accept();
        cout << "Enter Bonus : ";
        cin >> bonus;
    }
    void display() {
        Employee::display();
        cout << "Bonus : " << bonus << endl;
    }

    string getType() { return "Manager"; }
};

class Salesman : virtual public Employee {
private:
    double commission;
public:
    Salesman() : commission(0.0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void setCommission(double commission) { 
        this->commission = commission; 
    }
    double getCommission() {
         return this->commission;
         }

    void accept() {
        Employee::accept();
        cout << "Enter Commission : ";
        cin >> commission;
    }
    void display() {
        Employee::display();
        cout << "Commission : " << commission << endl;
    }

    string getType() { return "Salesman"; }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() {}
    SalesManager(int id, double salary, double bonus, double commission): Employee(id, salary) //, Manager(id,salary, bonus), Salesman(id,salary,commission)  
    {
        setBonus(bonus);           
        setCommission(commission);
    }

    void accept() {
        Employee::accept();
        cout << "Enter Bonus : ";
        double b; 
        cin >> b; 
        setBonus(b);
        cout << "Enter Commission : ";
        double c; 
        cin >> c; 
        setCommission(c);
    }
    void display() {
        Employee::display();
        cout << "Bonus : " << getBonus() << endl;
        cout << "Commission : " << getCommission() << endl;
    }

    string getType() { return "SalesManager"; }
};

int main() {
    vector<Employee*> employees;
    int choice = -1;   // initialize with non-zero to enter loop

    while(choice != 0) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Manager\n";
        cout << "2. Add Salesman\n";
        cout << "3. Add SalesManager\n";
        cout << "4. Display count of all employees (by designation)\n";
        cout << "5. Display All Managers\n";
        cout << "6. Display All Salesmen\n";
        cout << "7. Display All SalesManagers\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        Employee* emp = NULL;
        switch(choice) {
            case 1:
                emp = new Manager();
                emp->accept();
                employees.push_back(emp);
                break;
            case 2:
                emp = new Salesman();
                emp->accept();
                employees.push_back(emp);
                break;
            case 3:
                emp = new SalesManager();
                emp->accept();
                employees.push_back(emp);
                break;
            case 4: {       
                int m=0, s=0, sm=0;
                for(auto e : employees) {
                    if(e->getType()=="Manager") m++;
                    else if(e->getType()=="Salesman") s++;
                    else if(e->getType()=="SalesManager") sm++;
                }
                cout << "Managers: " << m << endl;
                cout << "Salesmen: " << s << endl;
                cout << "SalesManagers: " << sm << endl;
                break;
            }
            case 5:
                for(auto e : employees)
                    if(e->getType()=="Manager") { e->display(); cout<<"----------------\n"; }
                break;
            case 6:
                for(auto e : employees)
                    if(e->getType()=="Salesman") { e->display(); cout<<"----------------\n"; }
                break;
            case 7:
                for(auto e : employees)
                    if(e->getType()=="SalesManager") { e->display(); cout<<"----------------\n"; }
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    // Cleanup
    for(auto e : employees) delete e;

    return 0;
}