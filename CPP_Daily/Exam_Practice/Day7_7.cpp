#include<iostream> 

using namespace std; 
class ArithmeticException
{
    private: 
    string message; 
    public: 
    ArithmeticException( string message)
    {
        this->message = message; 
    }
    string getMessage( void )
    {
        return this->message; 
    }
}; 
void acceptRecord(string msg , int &number)
{
    cout<<msg; 
    cin>>number; 
}
void printRecord(int res)
{
    cout<<"res : "<<res<<endl; 
}
int main()
{
    cout<<"Resource opened"<<endl; 
    int num1; 
    acceptRecord("num1 : ",num1);
    
    int num2; 
    acceptRecord("num2 : ",num2); 

    try
    {
        if(num2 == 0)
        {
            //throw 10; 
            //throw 11.33; 
            ArithmeticException ex("Divide by zero"); 
            throw ex; 
        }
        else 
        {
            int res = num1 / num2; 
            printRecord(res); 
        }
    }
    catch(ArithmeticException ex)
    {
       cout<<ex.getMessage()<<endl;  
    }
    catch(int ex)
    {
        cout<<"int : exception caught"<<endl; 
    }
    catch(double ex)
    {
        cout<<"double : exception caught"<<endl; 
    }
    


    cout<<"Resource close"<<endl;
    return 0;
}
