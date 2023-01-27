#include "bits/stdc++.h"
using namespace std;

// Recursion
// Permutation ( or number of combinatons possible ) for  ABC
//                   ABC ACB BAC BCA CBA CAB


void perm(string str,int index){
    if(index>=str.length()){
        cout<<str<<endl;
        return;
    }

for(int i=index;i<str.length();i++){
    swap(str[index],str[i]);
    perm(str,index+1);
    swap(str[index],str[i]);
}
}

int main(){
    string str="ABC";
    perm(str,0);
}