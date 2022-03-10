#include<bits/stdc++.h>
using namespace std;

// print susbset of array using bitmask 
// also print the XOR of every subset elements    (2Q in one Q)   :)
// bitmask L2 in copy. Check the copy for clear unnderstanding.





int main(){

int n=3;                // length/size of array
int arr[]={1,2,3};      // Array
int total_xor=0;

// number of subset form is always equal to 2
// (1<<n) is giving us 2³ =8 if n=3, but loop would work from 0
// so (1<<n)-1    if n=3 we will get 2³-1=7 loop 0 to 7

for(int num=0;num<=(1<<n)-1;num++){
    vector <int> v;    //storing each subset one by one
    int XOR=0;
    for(int bit=0;bit<=(n-1);bit++){
        if(num&(1<<bit))
        v.push_back(arr[bit]);
    }
    for(auto i:v){
        cout<<i<<" ";
        XOR=XOR^i;
    }
cout<<"     xor is => "<<XOR<<"\n";

 total_xor = total_xor^XOR; 

}

cout<<" \n Total subset XOR IS = "<<total_xor<<" however it wil always zero just showing proof";


return 0;

}