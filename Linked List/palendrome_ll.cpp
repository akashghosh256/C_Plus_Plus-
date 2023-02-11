Approach:

Following are the steps to this approach:-

Find the middle element of the linked list. Refer to this article to know 
the steps 
Reverse linked list from next element of middle element. 
Iterate through the new list until the middle element reaches the end of the list.
Use a dummy node to check if the same element exists in the linked list from 
the middle element.

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};

void insertNode(node* head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

node* reverse(node* ptr) {
    node* pre=NULL;
    node* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}

bool isPalindrome(node* head) {
    if(head==NULL||head->next==NULL) return true;
        
    node* slow = head;
    node* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
    node* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->num != slow->num) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}

int main() {
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,2);
    insertNode(head,1);
    isPalindrome(head)? cout<<"True" : cout<<"False";
    return 0;
}
Output: True

Time Complexity: O(N/2)+O(N/2)+O(N/2)

Reason: O(N/2) for finding the middle element, reversing the list 
from the middle element, and traversing again to find palindrome respectively.

Space Complexity: O(1)

Reason: No extra data structures are used.