#include "bits/stdc++.h"
using namespace std;

// no. of ways to climb the stairs if we can only jump 1,2 or 3 stairs together
// using recursion 

int jump(int n){

if(n<0)
return 0;

if(n==0)
return 1;

return jump(n-1)+jump(n-2)+jump(n-3);

}

int main(){

cout<<jump(4);

}