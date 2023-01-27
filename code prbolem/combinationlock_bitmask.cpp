#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<int> arr){
 

    int flag=1;
 for(int num=0;num<=(1<<n)-1;num++){
     int sum=0;
     for(int bits=0;bits<=n-1;bits++){
         if(num&(1<<bits))
         sum+=arr[bits];

         else sum-=arr[bits];
     }

// if(sum%360==0)   it is for if n=4 arr={180,180,180,180} it is also true .
if(sum%360==0){
    flag=1;
    break;
}
else flag=0;
 }
if(flag)
cout<<"YES\n";
else cout<<"NO\n";
}

int main(){

 int n;
cin>>n;
vector<int> arr;
int p;
int flag=1;

for(int i=0;i<n;i++){
    cin>>p;
    if(p<1 || p>180){
        flag=0;
        break;
    }
     else {arr.push_back(p);}
}

if(flag==1)
solve(n,arr);
else cout<<"NO\n";
return 0; 

}