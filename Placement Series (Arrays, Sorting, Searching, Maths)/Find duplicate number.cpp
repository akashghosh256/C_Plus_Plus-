Find the Duplicate number in array
https://leetcode.com/problems/find-the-duplicate-number/solution/

// Brute Method

int n =  Integer.parseInt(f.readLine());
         StringTokenizer st = new StringTokenizer(f.readLine());
         int[] a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(st.nextToken());
            }

        int p=0;
        Arrays.sort(a);
        print(a);
       for(int i=0;i < n-1;i++){
         if(a[i]==a[i+1]){
            p=a[i];
            break;
         }
        
       } 
       out.println(p);

//Optimal soln- Linked list(No need to create LL just for thinking, here aray will workout)  - Tortoise Method/Fast & slow pointer method

class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        } while( slow != fast);
        
             
         // Now this will help us to know the entry point of the cycle,this where we will find the duplicate element
        fast = nums[0];
        while( slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
}
