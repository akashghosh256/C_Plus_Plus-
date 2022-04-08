#include <bits/stdc++.h>
using namespace std;
// comperator are user defined function , it help us to sort 
// any type of data types like array,pair etc according to our choice


// Example 1----------------------------------------------------------------
// sorting array in descending order

/*
// comperator function to check greater number
bool compare(int a, int b){
    cout<<"Now comparing "<<a<<" and "<<b<<endl;
    return a>b; // will return true if a>b
}


int main(){

 int ar[]={5,2,1,3,4,6};

// passing compare function to sort function to sort the array in descending order
 sort(ar , ar+6 , compare);

cout<<"Final sorted array is: ";
 for(int i=0; i<6; i++)
 cout<<ar[i]<<" ";


}  
*/
// Example 2:-----------------------------------------------------------------------
// sorting pair according to i.second


bool comp(pair<int,int>p1, pair<int,int>p2){
    if(p1.second < p2.second){
    return true; }
    else if(p1.second == p2.second){
        if(p1.first > p2.second) return true;
    }
    else return false;

}

int main(){
    pair<int,int>a[]={{1,2},{3,2},{2,5}};
    // Normal sort : sorts according to i.first
    sort(a,a+3);
    cout<<"Normal sort: \n";
    for(int i=0; i<3;i++){
    cout<<a[i].first<<" "<<a[i].second<<endl;
    }

// Comparator sort is define  to sort according to i.second (see) 
    sort(a , a+3 , comp);
   cout<<"Comparator sort: \n";
    for(int i=0; i<3;i++){
    cout<<a[i].first<<" "<<a[i].second<<endl;
    }
    return 0;
}