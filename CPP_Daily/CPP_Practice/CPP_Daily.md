PCALL - Preprocessor , Compiler , Assembler , Linker , Loader

isoeR



Command to run CPP Program - 

g++ hello.cpp -o hello.exe

hello.exe

--------------------------

Que. linker links main.o and .lib/.dll or .so filer into a.exe but what are these .lib / .dll /.so files?

`.lib`, `.dll`, and `.so` files are types of libraries used in C++ development:



\- \*\*.lib\*\* (Static Library or Import Library, Windows):  

&nbsp; Contains compiled code that can be linked directly into your executable at build time. If you use a static `.lib`, its code becomes part of your `.exe`.



\- \*\*.dll\*\* (Dynamic Link Library, Windows):  

&nbsp; Contains compiled code that is loaded at runtime. Your program uses an import `.lib` to know how to call functions in the `.dll`, but the actual code stays in the `.dll` and is loaded when your program runs.



\- \*\*.so\*\* (Shared Object, Linux/Unix):  

&nbsp; Similar to `.dll`, but used on Linux/Unix systems. It contains code that is loaded dynamically at runtime.



\*\*\*

These files provide reusable code (functions, classes, etc.) that you can use in your programs without having to write everything yourself.

example -#include <iostream> // Reusable code for input/output

--------------------------------------------------------------------------------------------------------



# Datatypes

1.Fundamental

2.Derived

3.User Defined



---------------------------------------------



Que. Why pointers are used in C but not in C++ struct with member functions

First code (C) uses pointers because functions are separate from the struct; passing pointers is needed to modify the original struct data.



Second code (C++ style) embeds functions inside the struct; functions can directly modify the struct's own data members using this pointer implicitly, so no explicit pointer parameter is needed.



What to use in C -

Declare structs to hold data only.

Use separate functions taking struct pointers to operate on the data.



What to use in C++ -

Use structs or classes with member functions inside.

Call functions on struct objects directly.

----------------------------------------------------------------------------------------------------

Remember Syntax

emp.Employee::printRecord( ); //message passing 





-----------------------------

Never forgot to write 



using namespace "namespace\_name"

or access variable in namespace using :: (Scope Resolution Operator)

--------------------------------------------------------------------------

//typedef is used to create the alias for existing data type (class / structure)

//reference is used to create alias of existing object





-------------------------------------------------------------------------------

Que. Why malloc return type is void\* ?

// void\* malloc(size\_t size); 



malloc(size\_t size) means: “Give me a block of memory of size bytes.”



But malloc doesn’t know what you want to store there (int? float? struct?).



That’s why it returns a generic pointer → void\*.



👉 A void\* pointer in C means:



"This is a pointer to some memory, but I don't know the data type yet."

So after malloc, you decide the type by typecasting it.



Syntax -



int \*p = (int\*) malloc(5 \* sizeof(int));   // memory for 5 integers

float \*q = (float\*) malloc(10 \* sizeof(float)); // memory for 10 floats



🔹 free(ptr);



When you call malloc, memory is given from the heap.



That memory will not be automatically released when the function ends.



If you keep allocating and never release → memory leak (program wastes memory).



👉 free(ptr); tells the system:



"I’m done using this memory, you can take it back."



So after free(ptr);



The memory block in the heap (that stored 100) is returned to the OS.



But the pointer ptr still holds the old address (like 1000 in your diagram).



This makes it a dangling pointer → dangerous if you accidentally use it.



🔹 ptr = NULL;



After free, ptr is still pointing to freed memory.



Accessing it (\*ptr) would be undefined behavior.



Setting ptr = NULL; makes it safe.



-----------------------------------------------------------------------

Dynamic Allocation in C



&nbsp;int \*ptr = new int; 



🔹 What happens here



new int → asks the system for memory in the heap for one integer.



It returns the address of that memory (just like malloc).



ptr (an int\*) will store that address.



So now ptr points to a heap location that can store 1 integer.



\## Some other Syntaxes -



//int \*ptr = new int; // Default value garbage; 

&nbsp;   

//int \*ptr = new int( ); // default value 0 



//int \*ptr = new int(3);  // value at ptr = 3





\## Array of Integers



//int \*ptr = new int\[3]; //12 bytes //here default will be garbage



int \*ptr = new int\[3](); //12 bytes //here default value 0





\## Syntax for 2D array



----Array of Pointers-----

// int \*\*ptr = (int\*\*)calloc(4 , sizeof(int\*));



// int \*\*ptr = new int \*\[4];







----------------------------------------------------------------------

DAY 5



\#Association -(has-a) relationship



1\. Composition - Tight Coupling (Day5\_1.cpp)

&nbsp;	

2\. Aggregation - Loose Coupling (Day5\_2.cpp)



class Date {



&nbsp;	//TODO

};



class Employee{



&nbsp;	Date joindate; //Here we create object inside object (object will compulsorily get space inside Employee class) Therefore Tight Coupling 



&nbsp;	Date \*joindate; //Here we created pointer , object is not stored inside object of Employee , this will be somewhere in heap memory(Loose Coupling)



};





---------------------



\#Inheritance

\- is a relationship

\- Also called as GENERALISATION
- Inheritance is a journey form GENERALIZATION TO SPECIALIZATION

\- In C++, default mode of inheritance is private

\- All the non static data members of base class get space inside object of derived class. In other words, non static data members of base class, inherit into derived class.

\- Using derived class, we can access static members of base class. In other words, static data members of base class, inherit into derived class

\- All the data members( static/non static) of base class of any access specifier(private/protected/public), inherit into derived class but only non static data member get space inside object

\- Size of object of Base class = size of of all the non static data members declared in base class.

\- Size of object of Derived class = size of of all the non static data members declared in base class + size of of all the non static data members declared in derived class.

\- Static and Non static member functions are inherited into derived class



Following function do not inherit into derived class:

1.Constructor

2.Destructor

3.Copy constructor

4.Assignment operator function

5.Friend function



* If we create object of derived class then first base class constructor gets called and then derived class constructor gets called. Destructor calling sequence is exactly opposite.
* From any constructor of derived class, by default, base class's parameterless constructor gets called
* If we want to call, any constructor of base class from constructor of derived class then we should use constructor's base initializer list.
(Day5_4.cpp)




\# TYPES OF INHERITANCE - 



1. Implementation Inheritance 
2. Interface Inheritance



Both has 
1. Single Inheritance

2\. Multiple Inheritance

3\. Hierarchical Inheritance

4\. Multilevel Inheritance




# Shadowing

If name of base class and derived class member function is same and if we try to call such member function on object of derived class then preference is given to the derived class member function. **Here derived class member function hides implementation of inherited function**. This process is called shadowing.

Without changing implementation of existing class, if we want to extend meaning of that class then we should use inheritance









