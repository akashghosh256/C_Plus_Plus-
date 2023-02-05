#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Function to find Kth permutation sequence of first N positive integers
    string getPermutation(int n, int k) {
      // Initialize the factorial value
      int fact = 1;

      // Store the first N positive integers in a vector
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i; // Calculating factorial as well as storing the numbers
        numbers.push_back(i);
      }
      numbers.push_back(n);  // number starts from 1 so n is pushed

      // Initialize the answer string
      string ans = "";
      k = k - 1; // Convert k to 0-indexed

      // Loop until all elements are used in the permutation
      while (true) {
        // Calculate the index of next number to add to the answer string
        int index = k / fact;

        // Add the number at the calculated index to the answer string
        ans = ans + to_string(numbers[index]);

        // Remove the number from the vector so it is not used again
        numbers.erase(numbers.begin() + index);

        // If all numbers have been used, break the loop
        if (numbers.size() == 0) {
          break;
        }

        // Update k and the factorial value for the next iteration
        k = k % fact;
        fact = fact / numbers.size();
      }

      // Return the Kth permutation sequence
      return ans;
    }
};

int main() {
  int n = 3, k = 3; // Example inputs
  Solution obj; // Create an object of the Solution class

  // Call the getPermutation function to get the Kth permutation sequence
  string ans = obj.getPermutation(n, k);

  // Output the result
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}


// Time Complexity: O(N) * O(N) = O(N^2)

// Reason: We are placing N numbers in N positions. This will take O(N) time. 
//For every number, we are reducing the search space by removing the element 
//already placed in the previous step. This takes another O(N) time.

// Space Complexity: O(N) 

// Reason: We are storing  the numbers in a data structure(here vector)