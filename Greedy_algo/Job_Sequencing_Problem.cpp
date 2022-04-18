
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
// Link : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 



// comperator to sort according to max profit
bool comparison(Job a,Job b){
    return (a.profit > b.profit);
}


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
  vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
  sort(arr, arr+n, comparison);
  // storing the deadline of highest profit
  int maxi = arr[0].dead;

// Now storing the maximum deadline we have all over(it will be maxium
  // days we can take)
  for(int i=0;i<n;i++){
    maxi = max(maxi, arr[i].dead);

  }

// Array  to store the assign work
int slot[maxi+1];
for(int i=0; i<=maxi;i++)
slot[i]=-1;

int countjobs = 0, jobprofit=0;

// i loop is iterating from maxmimum profit
for(int i=0; i<n ; i++){

// j loop is for the deadline of i 
    for(int j = arr[i].dead ; j>0; j--){

        //if slot is empty for that time or before then true
        if(slot[j] == -1){
            slot[j] = i;
            countjobs++;
            jobprofit+=arr[i].profit;
            break;

        }
    }
}
// Just to return answer in vector form
vector<int> answer;
answer.push_back(countjobs);
answer.push_back(jobprofit);
return answer;
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
  return 0; 
}


  // } Driver Code Ends