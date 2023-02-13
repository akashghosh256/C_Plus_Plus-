https://leetcode.com/problems/rotate-list/description/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // return head if linked list is empty or has only one node or k is 0
    if(head == NULL || head->next == NULL || k == 0) return head;

    // calculate the length of the linked list
    ListNode* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }

    // link last node to first node to form a circular linked list
    temp->next = head;

    // handle the case where k is greater than the length of the list
    k = k % length; 

    // find the end of the list after rotating k places
    int end = length - k; 

    // move to the end of the list
    while(end--) temp = temp->next;

    // break the link between the last node and the first node
    head = temp->next;
    temp->next = NULL;

    // return the head of the rotated list
    return head;  
    }
};
Time Complexity: O(length of list) + O(length of list – (length of list%k))

Reason: O(length of the list) for calculating the length of the list. O(length of the list – (length of list%k)) for breaking link.

Space Complexity: O(1)

Reason: No extra data structure is used for computation.