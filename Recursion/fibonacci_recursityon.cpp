The time complexity of the Fibonacci series algorithm that uses recursion is O(2^n).

The reason for this is that for each call of the function, two new calls are made, 
one with the input decremented by 1 and the other with the input decremented by 2. 
This means that the number of recursive calls made is roughly equivalent to the Fibonacci sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

 Yes, the space complexity of the Fibonacci series algorithm that uses recursion is also O(2^n).

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

