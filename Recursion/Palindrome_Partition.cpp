#include <bits/stdc++.h>

using namespace std;

// Solution class to find all the possible palindromic partitions of a given string
class Solution {
  public:
    // Public function to return all possible palindromic partitions of a string
    vector < vector < string >> partition(string s) {
      vector < vector < string > > res; // To store all possible partitions
      vector < string > path; // To store the current partition
      partitionHelper(0, s, path, res); // Call the helper function with initial index = 0
      return res;
    }

  // Recursive function to find all possible palindromic partitions
  void partitionHelper(int index, string s, vector < string > & path,
    vector < vector < string > > & res) {
    // If the entire string is processed, add the current partition to the result
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    // Iterate through all substrings starting from the current index
    for (int i = index; i < s.size(); ++i) {
      // If the current substring is a palindrome
      if (isPalindrome(s, index, i)) {
        // Add the substring to the current partition
        path.push_back(s.substr(index, i - index + 1));
        // Recursively call the partitionHelper function with the next index
        partitionHelper(i + 1, s, path, res);
        // Backtrack by removing the last added substring
        path.pop_back();
      }
    }
  }

  // Function to check if a given substring is a palindrome or not
  bool isPalindrome(string s, int start, int end) {
    // Compare characters from both ends towards the middle
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};

// Main function
int main() {
  string s = "aabb"; // Input string
  Solution obj; // Create an object of the Solution class
  vector < vector < string >> ans = obj.partition(s); // Get all possible partitions
  int n = ans.size(); // Total number of partitions
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  // Iterate through all the partitions
  for (auto i: ans) {
    cout << "[ ";
    // Iterate through all the substrings in a partition
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
}


// OUTPUT:
// The Palindromic partitions are :-
//  [ [ a a b b ] [ a a bb ] [ aa b b ] [ aa bb ] ]


// Time Complexity: O( (2^n) *k*(n/2) )

// Reason: O(2^n) to generate every substring and O(n/2)  
// to check if the substring generated is a palindrome. O(k) is for 
// inserting the palindromes in another data structure, where k  is the 
// average length of the palindrome list.

// Space Complexity: O(k * x)

// Reason: The space complexity can vary depending upon the length of 
// the answer. k is the average length of the list of palindromes and
//  if we have x such list of palindromes in our final answer. 
//  The depth of the recursion tree is n, so the auxiliary space 
//  required is equal to the O(n).