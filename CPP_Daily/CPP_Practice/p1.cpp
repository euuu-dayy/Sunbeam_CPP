# include <stdio.h>
# include <string.h>
int main4(){
    //In C struct can be defined inside main
    struct Employee {
        char name[50];
        int empid;
        float salary;
    };

    struct Employee emp;

    //emp.name = "John Doe"; // This will cause an error, need to use strcpy
    //In C++, you can't assign a string literal directly to an array using the assignment operator (=). This is because an array is not a modifiable lvalue, meaning it can't be assigned a new value directly.
    strcpy(emp.name, "John Doe"); // Correct way to assign a string to a char array
    emp.empid = 12345;
    emp.salary = 55000.50;

    printf("Employee Name: %s\n", emp.name);
    printf("Employee ID: %d\n", emp.empid);
    printf("Employee Salary: %.2f\n", emp.salary);

}

int main3()
{   
    
    struct Employee
    {
        //structure members
        char name[20]; //20 bytes 
        int empid; // 4 
        float salary; // 4 
        char gender;
    };
    struct Employee emp = {"Ketan",1,1000.00,'M'}; 
    // struct Employee  : Data-type 
    // emp : variable / object 
    

    printf("Name : %s\n", emp.name);
    printf("Empid : %d\n", emp.empid);
    printf("Salary : %.2f\n", emp.salary);
    printf("Gender : %c",emp.gender);
    return 0;
}

int main2(){

    struct Employee
    {
        //structure members
        char name[20]; //20 bytes 
        int empid; // 4 
        float salary; // 4 
    };

    struct Employee emp; 
    // struct Employee  : Data-type 
    // emp : variable / object 
    printf("Name : ");
    scanf("%s", emp.name);

    printf("Empid : ");
    scanf("%d", &emp.empid);

    printf("Salary : ");
    scanf("%f", &emp.salary);

    printf("Name : %s\n", emp.name);
    printf("Empid : %d\n", emp.empid);
    printf("Salary : %.2f\n", emp.salary);
    return 0;
}
int main1(){
    char name[20];
    int empid;
    float salary;

    printf("Name: ");
    scanf("%s", name);

    printf("Empid : ");
    scanf("%d", &empid);

    printf("Salary : ");
    scanf("%f", &salary);

    printf("Name : %s\n", name);
    printf("Empid : %d\n", empid);
    printf("Salary : %.2f\n", salary);
    return 0;
}