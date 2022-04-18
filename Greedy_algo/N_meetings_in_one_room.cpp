
//Q1 > There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
//What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
// Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


struct meetings{
    int st;       //st =start time of meet
    int ed;       //ed =end time of meet
    int ps;       //ps =order of meeting 1,2,3....n
};

bool comp(struct meetings m1 , struct meetings m2){

    if(m1.ed < m2.ed) return true;
    else if(m1.ed> m2.ed) return false;
    else if(m1.ps < m2.ps) return true;
    else return false;
}



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {  // Adding it to structure 
	
        meetings meet[n];
        for(int i=0;i<n;i++){
            meet[i].st=start[i] , meet[i].ed=end[i], meet[i].ps=i+1;
        }

//cout<<"Before sort \n";
//for(int i=0;i<n;i++){ 
  //          cout<<meet[i].st<<" " << meet[i].ed<<" " << meet[i].ps<<endl;
    //    }

    sort(meet, meet+n, comp);
    
   // cout<<"After sort \n";
//for(int i=0;i<n;i++){
  //          cout<<meet[i].st<<" " << meet[i].ed <<" "<< meet[i].ps<<endl;
    //    }

    vector<int> ans;
int limit = meet[0].ed;
ans.push_back(meet[0].ps);


for(int i=1;i<n;i++){
    if(meet[i].st > limit){
        limit = meet[i].ed;
        ans.push_back(meet[i].ps);
    }
}
//cout<<"meetings are \n";
//for(auto i:ans) cout<<i<<" ";




 return ans.size();
        
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends