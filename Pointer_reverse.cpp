#include <bits/stdc++.h>
using namespace std;

char *Reversestring(char *pstring){
if(pstring == NULL)
return NULL;
char *pstart = pstring;
char *pend = pstring + strlen(pstring) - 1;

while(pstart < pend){
    char temp = *pstart;
    *pstart = *pend;
    *pend = temp;

    pstart++;
    pend--;

}

return pstring;
}

int main(){

char str[100] = "akashghosh256";
cout<<"Reverse String is: "<<Reversestring(str)<<endl;

}