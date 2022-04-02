#include <bits/stdc++.h>
using namespace std;

// code to convert alphabets to string and vice versa
int main(){

string str="hello_?king456z", s1=" ",s2=" ",s3=" ";

// To print special characters
for(int i=0;i<str.length();i++){

/* 
  To check character is alphabet or number
  This  are the range of numbers(0-9) , small and capital alphabets 
  (A-Z ,a-z) outside this range all are special characters

 for numbers => (str[i]>=48 && str[i]<=57)
 for (A-Z) => (str[i]>=65 && str[i]<=90)
 for (a-z) => (str[i]>=97 && str[i]<=122))

*/

  if ((str[i]>=48 && str[i]<=57)||
        (str[i]>=65 && str[i]<=90)||
        (str[i]>=97 && str[i]<=122))
        {
      s1=s1+str[i];
    }
// Else it will be a special character (!@#$%^&*?)
 else s2 = s2 + str[i];



// To store ASCII VALUE of all characters
// OR TO ADD INTEGER TO A  NEW STRING 
int asc_value = int(str[i]);
// converting int to str value and adding in  new string
s3 = s3 + to_string(asc_value) + " ";


// TO REPLACE ALPHABETS WITH NEXT IMMEDIATE ALPHABET
if(str[i]=='z') str[i]='a';
else str[i]=(char)(str[i]+1);
}

cout<<"only characters or digits are: "<<s1<<endl;
cout<<"Special characters are: "<<s2<<endl;
cout<<"ASCII  values of all the character :"<<s3<<endl;
cout<<"New string after incrementation: "<<str<<endl;



return 0;
}