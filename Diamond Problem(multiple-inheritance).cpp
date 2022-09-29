#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------C++ virtual function---------------------------------------------
A C++ virtual function is a member function in the base class that you redefine in a derived class. 
It is declared using the virtual keyword.
It is used to tell the compiler to perform dynamic linkage or late binding on the function.
There is a necessity to use the single pointer to refer to all the objects of the different classes. 
So, we create the pointer to the base class that refers to all the derived objects. 
But, when base class pointer contains the address of the derived class object, always executes the 
base class function. This issue can only be resolved by using the 'virtual' function.
A 'virtual' is a keyword preceding the normal declaration of a function.
When the function is made virtual, C++ determines which function is to be invoked at the runtime 
on the type of the object pointed by the base class pointer.

*/
//------------------------------------------ CODE ----------------------------------------

class A {			// Granparent Class
       public :
	    void funA ( ) {
		cout<< "Hi from class A"<<endl;
       }
};

class B : virtual public A {      // Parent Class 1
       public :
void funB() {
	cout<< "Hi from class B"<<endl;
}
};

class C : virtual public A {		// Parent Class 2
       public : 
	   void funC(){
		cout<< "Hi from class C"<<endl;
	   }
} ;

class D: public B , public C{		// Only Child Class
    
   public:
   void funD(){
	cout<< "Hi from class D"<<endl;
   }
};

int main(){
 //B b1;
 //C c1;
 D d1;
 d1.funA();
 d1.funB();
 d1.funC();
 d1.funD();
}
