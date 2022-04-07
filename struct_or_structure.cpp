#include <bits/stdc++.h>
using namespace std;

/*
 where we need to store a group of data whether of similar data types or 
 non-similar data types. We have seen Arrays in C++ which are used to store 
 set of data of similar data types at contiguous memory locations.
*/

struct students{

string name;
float gpa;

};  // STRUCT always ends with ;

int main(){

  students Teacher;  // creating object , for just simple string
  Teacher.name = " Mr. Singh ";
  cout<<Teacher.name<<"\n";


  students firstperiod[10]; // creating object array 
  firstperiod[0].name="Jerry";
  firstperiod[0].gpa=9.40;

  firstperiod[1].name="Doraemon";
  firstperiod[1].gpa=9.46;

  cout<<firstperiod[0].name<<" "<<firstperiod[0].gpa<<"\n";
  cout<<firstperiod[1].name<<" "<<firstperiod[1].gpa<<"\n";
 
}