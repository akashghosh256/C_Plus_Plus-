// Greatest Common Divisior of two numbers / H.C.F (HIGHEST COMMON FACTOR)

#include <bits/stdc++.h>
using namespace std;



int main(){
int a=18, b=8;
// using gcd function of C++
int GCD=__gcd(a,b);
cout<<"gcd is "<<GCD;
return 0;
}




/*

int main(){
// using Euclid Algotrithm to find gcd
int a=18 , b=8;

while(b!=0){
 int rem=a%b;
 a=b;
 b=rem;

}

cout<<"GCD is: "<<a;
return 0; 

}  */
