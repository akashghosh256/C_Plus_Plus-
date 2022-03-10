#include "bits/stdc++.h"
using namespace std;
// To print digit in text-----------------------
void spell(int n, string str[]){

if(n==0)
    return;

spell(n/10,str);
cout<<str[n%10]<<" ";


}
int main(){
string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
spell(452,str);
return 0;
}

