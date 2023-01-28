#include "bits/stdc++.h"
using namespace std;

 // Reversing an array using recursion
void reversef(int i,int ARR[],int n){
    if(i>=n/2){
        return;
    }

    swap(ARR[i],ARR[n-i]);
    reversef(i+1,ARR,n);
}

int main(){

    int ARR[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(ARR)/sizeof(ARR[0]);
    cout<<"Before Reverse: ";
    for(int i=0;i<n;i++){
        cout<<ARR[i]<<" ";
    }
    cout<<endl;
    cout<<"After Reverse: ";
    reversef(0,ARR,n-1);
    for(int i=0;i<n;i++){
        cout<<ARR[i]<<" ";
    }
}