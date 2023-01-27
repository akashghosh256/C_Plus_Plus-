
#include<bits/stdc++.h>
using namespace std;
// To print the the specific term from fibonacci series(0,1,1,2,3,5....n)-------------------------
// eg: n=5 , the 5th term in fibonacci series is 5                ^

int fib(int n)
{
if (n == 1 || n==0)
return n;
return fib(n-1) + fib(n-2);
}

int main ()
{
int n = 5;
cout << fib(n);
return 0;
}

