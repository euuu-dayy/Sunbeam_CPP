#include<iostream> 

using namespace std;
class Student 
{
    private: 
    int roll; 
    string name; 
    double marks; 
    public: 
    Student( void ) : roll( 0 ) , name(" ") , marks(0.0)
    {   }
    Student(string name , int roll , double marks) : name(name) , roll(roll) , marks(marks)
    {   }
    void accept( )
    {
        cout<<"Name : "; 
        cin>>name; 
        cout<<"Roll : "; 
        cin>>roll; 
        cout<<"Marks : "; 
        cin>>marks; 
    }
    void display( )
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
        cout<<"Marks : "<<marks<<endl;  
        cout<<endl; 
    }
}; 
int main4()
{
    Student **arr = new Student*[2]; 
    arr[0] = new Student("Rohan",1,33.33); 
    arr[1] = new Student("Amit",2,44.33);
    
    
    for(int index = 0 ; index < 2 ; index++)
        arr[index]->display( ); 
    for(int index = 0 ; index < 2 ; index++)
    {
        delete arr[index]; 
        arr[index] = NULL; 
    }   
    delete[] arr; 
    arr = NULL; 
    return 0;
}

int main3()
{
    Student *arr = new Student[2]; 
    for(int index = 0 ; index < 2 ; index++)
        arr[index].accept( ); 
    for(int index = 0 ; index < 2 ; index++)
        arr[index].display( ); 
    delete[] arr;// To avoid memory leakage  
    arr = NULL; // To avoid dangling pointer 
    return 0;
}

int main2()
{
    Student *arr[2]; //array of pointers 
    arr[0] = new Student("Ketan",1,33.33); 
    arr[1] = new Student("Rohan",2,44.44);
    for(int index = 0 ; index < 2 ;index++)
        arr[index]->display( ); 
    
    for(int index = 0 ; index < 2 ;index++)
    {
         delete arr[index]; 
         arr[index] = NULL; 
    }      
    return 0;
}

int main()
{
    Student arr[2]; // array of objects 
    for(int index = 0 ; index < 2 ; index++)
        arr[index].accept( ); 
    for(int index = 0 ; index < 2 ; index++)
        arr[index].display( );  
    return 0;
}
