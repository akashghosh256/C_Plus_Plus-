// Just like structure and classes a union is a user defined data type 
// In union, all members share the biggest same memory location
// This is used to achieve polymorphism ic c/c++;

// Possible usage ?
// when we need only one value out of many that time we will use it.
// Get the actual data in parts. (Example: int vALUE, char bytes[4])

#include <bits/stdc++.h>
using namespace std;

// Example 1 ---------------------------------------------------------------------------------

///*

union square{
    int width;
    int height;
};

int getArea(int width, int height){
    
    return width*height;
}

int main(){

     square sqr;
    
     sqr.width = 10;
     sqr.height = 30;   // if we now put any other value in height, since they point to same memory location
                        // it will change value for all all variables pointing to the memory location
                        // 30 * 30 = 900

     // If we are passing only 10 in width , height will also have same value 10
     // as they share same memory location  : 10 * 10 =100
     cout<<getArea(sqr.width,sqr.height)<<endl;

}  

//*/


// Example 2 --------------------------------------------------------------------------------

/* 
union myunion{

    char bytes[4];
    unsigned int value;
};

int main(){

    myunion un;
    un.value = 0;
    un.value = 2;

    // gives set bits value 
    cout<< (int)un.bytes[0]<<endl;
    cout<< (int)un.bytes[1]<<endl;
    cout<< (int)un.bytes[2]<<endl;
    cout<< (int)un.bytes[3]<<endl;


}

*/