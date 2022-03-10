// code to print all the prime numbers between 1 to n terms 
// using "sieve of eratosthenes" technique
// Time Complexity : O(n*log(log n)) 

#include <bits/stdc++.h>
using namespace std;

int main(){

int n=10;                              // number of terms

vector<int> prime(n+1, 1);
prime[1]=0;
cout<<"\n";
for(int i=2;i<=n; i++){

if(!prime[i]){
cout<<"skip "<<i<<"\n";
continue;
}
cout<<"going in "<<i<<"\n";

for(int j=2*i; j<=n;j+=i){

cout<<"removed "<<j<<"\n";
prime[j]=0;
}
}
cout<<" \nPrime numbers are as follows ";
for(int i=1;i<=n;i++){
if(prime[i]!=0) cout<<i<<" ";
}
}