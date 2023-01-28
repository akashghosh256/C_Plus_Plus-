#include "bits/stdc++.h"
using namespace std;


// printing subset using recursion
// can be also done using bitmask
// bitmask done check it---------------------------------------
// EXAMPLE OF SUBSET : {1,2,3}  SUBSET : {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}

// STRIVER METHOD
void subset(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " ";
        }

        if(ds.size() == 0){
            cout<<"{}";  // to show empty set
        }

        cout << endl;
        return;

    }
    subset(ind+1, ds, arr, n);
    ds.push_back(arr[ind]);   // PICK
    subset(ind+1, ds, arr, n);
    ds.pop_back();   // NOT PICK
}

int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> ds;  // data structure to store the subset
    subset(0, ds, arr, n);
    return 0;

}
 // TC - O(2^n)  FOR EACH ELEMENT WE HAVE TWO CHOICES
// SC - O(n)  BECAUSE  DEPTH OF RECURSION STACK WILL BE N
// OUTPUT:
// {}
// 2
// 1
// 1 2
// 3
// 3 2
// 3 1
// 3 1 2

//--------------------------------------------------------------------------














// OLD METHOD

// void subset(vector<int>input,vector<int>output,int index){

// if(index>=input.size()){
// for(auto i:output){
// cout<<i<<" ";
// }

// cout<<endl;
// return;
// }


// subset(input,output,index+1);
// output.push_back(input[index]);
// subset(input,output,index+1);
// }

// int main(){
// vector<int> input={1,2,3};
// vector<int> output;
// subset(input,output,0);
// return 0;
// }

/*
OUTPUT
3 
2 
2 3 
1 
1 3 
1 2 
1 2 3 
*/
