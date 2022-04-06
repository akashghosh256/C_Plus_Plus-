/*
" THE GRAY CODE " (see wikipedia for more details) is a well-known concept.
One of its important properties is that every two adjacent numbers have exactly one
different digit in their binary representation.In this problem, we will give you n
non-negative integers in a sequence A[1..n] (0<=A[i]<2^64), such that every two
adjacent integers have exactly one different digit in their binary representation,
similar to the Gray code.
Your task is to check whether there exist 4 numbers
A[i1], A[i2], A[i3], A[i4] (1 <= i1 < i2 < i3 < i4 <= n) out of
the given n numbers such that A[i1] xor A[i2] xor A[i3] xor A[i4] = 0


CODECHEF LINK: https://www.codechef.com/problems/GRAYSC

*/

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    map<ll, ll> m;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    if (n >= 129)
    {
        cout << "Yes"
             << "\n";
        return 0;
    }

    bool isFound = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                ll val = a[i] ^ a[j] ^ a[k];
                ll cnt = m[val];

                if (a[i] == val)
                    cnt--;
                if (a[j] == val)
                    cnt--;
                if (a[k] == val)
                    cnt--;

                if (cnt >= 1)
                    isFound = true;
            }
        }
    }

    cout << (isFound ? "Yes" : "No") << "\n";

    return 0;
}