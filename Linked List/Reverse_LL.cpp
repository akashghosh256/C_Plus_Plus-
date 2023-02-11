
class Solution {
public:

    ListNode* reverseList(ListNode* head) {

       //step 1
        ListNode* prev_p = NULL;
        ListNode* current_p = head;
        ListNode* next_p;
       
       //step 2
        while(current_p) {

            next_p = current_p->next;
            current_p->next = prev_p;
            
            prev_p = current_p;
            current_p = next_p;
        }

        head = prev_p; //step 3
        return head;
    }
};

Time Complexity:

Since we are iterating only once through the list and achieving reversed list. Thus, the time complexity is O(N) where N is the number of nodes present in the list.

Space Complexity:

To perform given tasks, no external spaces are used except three-pointers. So, space complexity is O(1).