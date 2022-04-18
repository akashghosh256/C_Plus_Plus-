#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// Find minimum number of coins required for a amount

int main(){
cin.tie(0)->sync_with_stdio(0); 
cin.exceptions(cin.failbit);
#ifndef ONLINE_JUDGE
    freopen("errorf.in", "w", stderr);
#endif

int money[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int m=9; // size of array

int amount=1459; // Any amount to find number of coins
vector<int> ans; // it will store the notes required

for(int i=m-1;i>=0;i--){

while(amount>=money[i]){
  amount-=money[i];
  ans.push_back(money[i]);
}
}

cout<<"No. of coins required :"<<ans.size()<<endl;
cout<<"coins required are: ";
for(int i=0;i<ans.size();i++)
cout<<ans[i]<<" ";

return 0;

 }