

Node *mergeTwoLists(Node *a,Node *b){
    // Create a new node with a dummy value as the starting point for the result linked list
    Node *temp = new Node(0); 
    Node *res = temp;
    
    // Iterate through both linked lists until one of them is exhausted
    while( a!= NULL && b!=NULL){
        
        // Compare the data values of the current nodes in both linked lists
        if(a->data < b-> data){
        // Add the node from linked list 'a' to the result linked list
        temp->bottom = a;
        temp = temp -> bottom;
        a= a -> bottom;
        }
        
        // If the node from linked list 'b' is smaller, add it to the result linked list instead
        else{
            temp->bottom =b;
            temp = temp -> bottom;
            b = b-> bottom;
        }
    
    }
    
    // If there are still nodes remaining in linked list 'a', add them to the result linked list
    if(a) temp -> bottom = a;
    // If there are still nodes remaining in linked list 'b', add them to the result linked list
    else temp -> bottom = b;

    // Return the result linked list, starting from the first node after the dummy node
    return res -> bottom;

}



/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   
   // If the linked list is empty or contains only one node, return it as it is already flattened
   if( root == NULL || root->next == NULL){
       return root;
   }
   
   // Recursively flatten the next node
   root->next = flatten(root->next);
   // Merge the current node and the flattened next node
   root= mergeTwoLists(root,root->next);
   
   // Return the root of the merged linked list
   return root;
   
   
}

Time Complexity: O(N), where N is the total number of nodes present

Reason: We are visiting all the nodes present in the given list.

Space Complexity: O(1)

Reason: We are not creating new nodes or using any other data structure.