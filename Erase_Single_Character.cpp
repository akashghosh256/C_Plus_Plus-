Erase the single character at iterator position pos. 
link - https://www.geeksforgeeks.org/stdstringerase-in-cpp/

// CPP code to illustrate
// erase(iterator pos)

#include <iostream>
#include <string>
using namespace std;

// Function to demo erase
void eraseDemo(string str)
{
	// Deletes character at position 4
	str.erase(str.begin() + 4);

	cout << "After erase : ";
	cout << str;
}

// Driver code
int main()
{
	string str("Hello World!");

	cout << "Before erase : ";
	cout << str << endl;
	eraseDemo(str);

	return 0;
}

Output: 

Before erase : Hello World!
After erase : Hell World!
