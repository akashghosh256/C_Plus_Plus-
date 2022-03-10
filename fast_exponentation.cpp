#include "bits/stdc++.h"
using namespace std;
// FAST EXPONENATION----------------------------------------------------------------

int expo(int n,int p){

if(p==0)
return 1;

int ans=expo(n,p/2);
if(p&1){

// if(p&1) is True for odd power
return n * ans * ans;

}
else{

// True for EVEN POWER
    return ans*ans;

}
}

int main(){

// 2^6=64
cout<<expo(2,6);
return 0;
}
