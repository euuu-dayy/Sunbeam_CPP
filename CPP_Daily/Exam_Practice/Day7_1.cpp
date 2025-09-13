//Aim - To understand why we downcast and importance of typeid

#include<iostream>
#include<typeinfo>
using namespace std; 

class Shape
{
    protected: 
    float area; 
    public: 
    virtual void calculateArea( void ) = 0; // pure virtual function 
    void printRecord( )
    {
        cout<<"Area : "<<area<<endl; 
    }
}; 
class Rectangle : public Shape
{
    private: 
    float length; 
    float breadth; 
    public: 
    // non-overrided methods 
    void setLength(float length)
    {
        this->length = length; 
    }
    // non-overrided methods 
    void setBreadth(float breadth)
    {
        this->breadth = breadth; 
    }
    // overrided method 
    void calculateArea( void )
    {
        this->area = this->length * this->breadth; 
    }
    
}; 
class Math 
{
    public: 
    const static float PI;
    static float pow(float base , int index)
    {
        float result = 1.0; 
        for(int count = 1 ; count<=index ; count++)
        {
            result = result * base; 
        }
        return result; 
    } 
}; 
const float Math :: PI = 3.142; 
class Circle : public Shape
{
    private: 
    float radius; 
    public: 
    // non-overrided methods 
    void setRadius( float radius)
    {
        this->radius = radius; 
    }
    //overrided methods 
    void calculateArea( void )
    {
        this->area = Math::PI * Math::pow(this->radius , 2); 
    }
}; 
int menulist( void )
{
    int choice; 
    cout<<"0.Exit"<<endl; 
    cout<<"1.Rectangle"<<endl; 
    cout<<"2.Circle"<<endl;
    cout<<"Enter the choice : "; 
    cin>>choice; 
    return choice;  
}
void acceptRecord(Shape *shape)
{   
    //java --- instanceof
    if(typeid(*shape) == typeid(Rectangle))   // why we do downcast ,  1. to call non overrided methods of derived class , 2.to call datamembers of derived class
    {   
        //cout<<typeid(shape).name()<<endl; 
        //cout<<typeid(*shape).name()<<endl;                                                           
        Rectangle *rect = (Rectangle*)shape;
        float length , breadth; 
        cout<<"Length : "; 
        cin>>length; 
        rect->setLength(length); 
        
        cout<<"Breadth : "; 
        cin>>breadth; 
        rect->setBreadth(breadth);  
    }
    else if(typeid(*shape) == typeid(Circle)) //typeid - to identify which type of object it is 
    {
        Circle *circle = (Circle*)shape; 
        float radius; 
        cout<<"Radius : "; 
        cin>>radius; 
        circle->setRadius(radius);  
    }
    else 
       cout<<"Invalid Shape"<<endl; 
}
void printRecord(Shape *shape)
{
    shape->printRecord( ); 
}
int main()
{
    int choice; 
    while((choice = menulist())!=0)
    {
        Shape *shape = NULL;  // 1.Base class pointer (bcoz , to reduce defining of multiple pointers for seprate shapes)
        switch (choice)
        {
        case 1: 
            shape = new Rectangle( ); // upcasting 
            break;
        case 2: 
            shape = new Circle( ); // upcasting 
            break; 
        }
        if(shape!=NULL)
        {
            ::acceptRecord(shape); 
            shape->calculateArea( ); 
            ::printRecord(shape); 
        }
    }
    return 0;
}
