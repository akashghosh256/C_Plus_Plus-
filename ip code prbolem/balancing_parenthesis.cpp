/*  
code to write to check the paranthesis are balanced are not 
eg. ((())) , [[({})]]
*/


#include<iostream>
#include<stack>
#include<string>

using namespace std;

// to check all are in pairs

bool isitpairs(char opening, char closing){

if (opening=='(' && closing==')') return true;
else if(opening=='[' && closing == ']') return true;
else if( opening=='{' && closing == '}') return true;
else return false;

}


bool expisbalanced(string exp){

// created a stack to store the combinations
stack<char> s;

for(int i=0;i<exp.length();i++){

    if((exp[i]=='[')||(exp[i]=='{')||(exp[i]=='('))
    s.push(exp[i]);
   else if((exp[i]==']')||(exp[i]=='}')||(exp[i]==')'))
    {
        if(s.empty() || !isitpairs(s.top(),exp[i]))
         return false;
        else s.pop();

    }}

return s.empty() ? true:false;


}


int main(){

string exp;
cout<<"Enter expression : ";
cin>>exp;
 if(expisbalanced(exp))
 cout<<exp<<" is balanced :) " ;
 else cout<<exp<<" is not balanced :( ";

return 0;
  
}