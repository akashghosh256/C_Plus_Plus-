#include "bits/stdc++.h"
using namespace std;
// print counting using recursion---------------1 2 3 4 5...

// code to print in ascending order


// This is backtracking 
void count1(int n){
    if(n==0)
    return;

count1(n-1);
cout<<n<<" ";
}

// code to print in descending order
void count2(int n){
    if(n==0)
    return;

cout<<n<<" ";
count2(n-1);

}

int main(){
cout<<"Asscending order"<<endl;
count1(5);
cout<<endl;
cout<<"Descending order"<<endl;
count2(5);
return 0;
}
