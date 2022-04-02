#include <bits/stdc++.h>
using namespace std;
/* TO PRINT NUMBER OF DAYS BETWEEN TWO GIVEN DATES IN FORM OF STRINGS
EG: 
SAMPLE INPUT 
Jan 1 2000
Feb 3 2000 
SAMPLE OUTPUT : 33 

HERE INPUT IS GIVEN IN FORM OF STRING SO WE HAVE TO FIRST FIND THE INDEX 
OF YEAR , DATE , MONTH 
OR IF IT IS GIVEN IN NUMBER THEN JUST REMOVE SOME LINES


*/


// TO GET MONTH NUMBER
int get_month_index( string name )
{
    map<string,int> months
    {
        { "Jan", 1 },
        { "Feb", 2 },
        { "Mar", 3 },
        { "Apr", 4 },
        { "May", 5 },
        { "Jun", 6 },
        { "Jul", 7 },
        { "Aug", 8 },
        { "Sep", 9 },
        { "Oct", 10 },
        { "Nov", 11 },
        { "Dec", 12 }
    };

    const auto iter = months.find( name );
        return iter->second;
}




// A date has day 'd', month 'm' and year 'y'
struct Date {
    int d, m, y;
};

// To store number of days in
// all months from January to Dec.
const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31 };

// This function counts number of
// leap years before the given date
int countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be
    // considered for the count of leap years
    // or not
    if (d.m <= 2)
        years--;

    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
    // multiple of 100.
    return years / 4
        - years / 100
        + years / 400;
}

// This function returns number of
// days between two given dates
int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'

    // initialize count using years and day
    long int n1 = dt1.y * 365 + dt1.d;

    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n2 - n1);
}

int main() {



string date1,date2,month1,month2;
getline(cin,date1);
getline(cin,date2);


// EXTRACTING INFORMATION FROM STRING 
 stringstream st1(date1);
 stringstream st2(date2);
 string w;
 vector<string> dt1,dt2;
 // THIS FUNCTION STORES STORE THE WORDS ONE BY ONE 
    while (st1 >> w)
        dt1.push_back(w);

    while (st2 >> w)
        dt2.push_back(w);

int m1=get_month_index(dt1[0]);
int m2=get_month_index(dt2[0]);


int d1 = stoi(dt1[1]);
int d2 = stoi(dt2[1]);

int year1 = stoi(dt1[2]);
int year2 = stoi(dt2[2]);

cout<<"month1: "<<m1<<" date1: "<<d1<<" year1:"<<year1<<endl;
cout<<"month2: "<<m2<<" date2: "<<d2<<" year2: "<<year2<<endl;

Date df1 = { d1, m1, year1 };
Date df2 = { d2, m2, year2 };
 
    // Function call
cout << "Difference between two dates is "<< getDifference(df1, df2);


return 0;
}