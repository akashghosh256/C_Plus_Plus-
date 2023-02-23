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
                                        TWO STACKS METHOD
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
vector<int> ans;
if(root == NULL) return ans;
stack<TreeNode*> st1;
stack<TreeNode*> st2;
st1.push(root);
TreeNode *node;

while(!st1.empty())
{
    node = st1.top();
    st2.push(node);
    st1.pop();
    if(node -> left  != NULL) st1.push(node->left);
    if(node -> right != NULL ) st1.push(node -> right);
}

while(!st2.empty()){

ans.push_back(st2.top()->val);
st2.pop();

}
return ans;

    }
};

Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N+N)  we are using two stacks.



                                        ONE STACK METHOD  
    

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector < int > ans;
         TreeNode *cur = root;
  if (cur == NULL) return ans;

  stack < TreeNode * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
    TreeNode * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
       ans.push_back(temp -> val);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          ans.push_back(temp -> val);
        }
      } else cur = temp;
    }
  }
  return ans;
    }
};

Time Complexity: O(N)

Space Complexity: O(N)
