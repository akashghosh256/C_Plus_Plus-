
 Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        
        //int n = sizeof(nums)/sizeof(nums[0]);
        int n = nums.size();
        int k,l;
        for(k=n-2;k>+0;k--){
if(nums[k]< nums[k+1])
    break;}
    
 if(k<0){
     reverse(nums.begin(),nums.end());
 }
else{
     for(l=n-1;l>k;l--){
if(nums[l]> nums[k]){
    break;
}}
        swap(nums[k],nums[l]);
    reverse(nums.begin()+k+1,nums.end());
     }
 }
        
};