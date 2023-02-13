#include<bits/stdc++.h>
using namespace std;

// Define a class node with two variables - an integer "num" and a pointer "next"
class node {
    public:
        int num;
        node* next;
        // constructor for the class node
        node(int a) {
            num = a;
            next = NULL;
        }
};

// Function to insert a new node in the linked list
void insertNode(node* &head, int val) {
    // Create a new node with the given value
    node* newNode = new node(val);
    // If the linked list is empty, make the new node the head of the list
    if(head == NULL) {
        head = newNode;
        return;
    }
    // Traverse the list to find the last node
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    // Add the new node to the end of the list
    temp->next = newNode;
    return;
}

// Function to find the length of the linked list
int lengthOfLinkedList(node* head) {
    int length = 0;
    // Traverse the list to count the number of nodes
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}

// Function to reverse k nodes in the linked list
node* reverseKNodes(node* head, int k) {
    // If the list is empty or has only one node, return the head
    if(head == NULL || head->next == NULL) return head;
    // Find the length of the list
    int length = lengthOfLinkedList(head);
    // Create a dummy node to act as the head of the list
    node* dummyHead = new node(0);
    dummyHead->next = head;
    // Three pointers - pre, cur, and nex - to reverse the list
    node* pre = dummyHead;
    node* cur;
    node* nex;
    // Reverse the list in groups of k nodes
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i = 1; i < k; i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    // Return the new head of the list
    return dummyHead->next;
}

// Function to print the linked list
void printLinkedList(node* head) {
    // Traverse the list and print the value of each node
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<"\n";
}


int main() {
    node* head = NULL;
    int k = 3;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
    insertNode(head,7);
    insertNode(head,8);
    
    cout<<"Original Linked List: "; printLinkedList(head);
    cout<<"After Reversal of k nodes: "; 
    node* newHead = reverseKNodes(head,k);
    printLinkedList(newHead);
    
    return 0;
}
Output:

Original Linked List: 1->2->3->4->5->6->7->8
After Reversal of k nodes: 3->2->1->6->5->4->7->8

Time Complexity: O(N)

Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).

Space Complexity: O(1)

Reason: No extra data structures are used for computation.