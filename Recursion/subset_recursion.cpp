#include "bits/stdc++.h"
using namespace std;

// printing subset using recursion
// can be also done using bitmask
// bitmask done check it---------------------------------------
void subset(vector<int>input,vector<int>output,int index){

if(index>=input.size()){
    for(auto i:output){
        cout<<i<<" ";
    }

cout<<endl;
return;
}


subset(input,output,index+1);
output.push_back(input[index]);
subset(input,output,index+1);
}

int main(){
vector<int> input={1,2,3};
vector<int> output;
subset(input,output,0);
return 0;
}


OUTPUT
3 
2 
2 3 
1 
1 3 
1 2 
1 2 3 
