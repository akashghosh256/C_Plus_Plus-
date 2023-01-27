#include "bits/stdc++.h"
using namespace std;
//factorial using recursion work for small numbers 
//for big numbers check code of big_faactoral----------------------------------------------------------


int fact(int n){
    if(n==1)
    return 1;

    return n*fact(n-1);
}
int main(){

cout<<fact(5);

}