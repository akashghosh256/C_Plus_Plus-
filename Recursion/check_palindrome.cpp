#include "bits/stdc++.h"
using namespace std;

    // Check if a string is palindrome or not , using recursion

    bool check(int i ,string s, int n){

        if(i>=n/2) return true;  //  if i is greater than or equal to n/2 then return true

        if(s[i] != s[n-i-1]) return false;  //  if characters are not equal then return false

        return check(i+1,s,n); //
        
    }

    int main(){
        string s = "MADAM";
        int n = s.length();
        if(check(0,s,n)){
            cout<<"Palindrome";
        }
        else{
            cout<<"Not Palindrome";
        }

    }