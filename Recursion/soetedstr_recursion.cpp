#include "bits/stdc++.h"
using namespace std;
// To check array is sorted or not using recursion----------------------------------------------

bool check(vector<int> arr,int index){

if(index>=arr.size())
return true;
if(arr[index]<arr[index-1])
return false;

return check(arr,index+1);

}

int main(){

vector<int>ar={1,6,2,3,4,5};

bool ans=check(ar,1);

if(ans)
cout<<"sorted array";
else cout<<"unsorted array";

}