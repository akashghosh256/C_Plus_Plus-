/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

   LEFT -> ROOT -> RIGHT
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
vector<int> ans;
if(root == NULL) return ans;
stack<TreeNode*> s;
TreeNode *currNode = root;
//s.push(root);

while(true){
  
  if(currNode != NULL){
      s.push(currNode);
      currNode = currNode -> left;
  }
else{

if(s.empty()) break;
currNode = s.top();
s.pop();
ans.push_back( currNode -> val );
currNode = currNode->right;
}}

return ans;
        
    }
};

Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: In the worst case (a tree with just left children), the space complexity will be O(N).