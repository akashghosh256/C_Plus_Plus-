//Floyd’s slow and fast pointers approach work (best)----------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
   ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void display(ListNode *head){

    printf("\nCrerated  LL is :");
     ListNode *temp;
    temp = head;

       while (temp != NULL)
  {
     printf(" %d , ", temp->val);
     temp= temp->next;
  }
}


class Solution {
public:
   
bool hasCycle(ListNode *head) {

if(head == NULL || head -> next == NULL)
return false;

ListNode *fast = head;
ListNode *slow = head;

 

   

while(fast -> next && fast -> next -> next){
fast = fast -> next -> next;
slow = slow -> next;

if(fast == slow)
return true;
}

return false;
}
};


int main(){

ListNode *head = new ListNode(1111);
ListNode *temp = head;
ListNode *copy;
temp -> next = new ListNode(200);
temp = temp -> next;
copy = temp -> next = new ListNode(3223);
temp = temp -> next;
temp -> next = new ListNode(433);
temp = temp -> next;
temp -> next = new ListNode(554);
temp = temp -> next;
temp -> next = new ListNode(832);
temp = temp -> next;
temp->next = new ListNode(6666);
temp ->next =copy;

display(head);

/*Crerated  LL is : 1111 ,  200 ,  3223 ,  433 ,  554 ,  832 ,  3223 ,  433 ,  554 ,  
832 ,  3223 ,  433 ,  554 ,  832 ,  3223 ,  433 ,  554 ,  832 ,  3223 ,  433 ,  554 ,  
832 ,  3223 ,  433 ,  554 ,  832 ,  3223 ,  433 ,  554 , 832 ,  3223 ,  433 ,  554 , 
832 ,  3223 ,  433 ,  554 ,  832 ,  3223 ,  433 ,  554 ,....(infinte) 
*/

if(Solution().hasCycle(head))
cout << "Yes" << endl;
else
cout << "No" << endl; 

//Output: Yes

return 0;

}


//-----------------------------------------------------------------------------------------------------------------------
// Using Hashing Method  (ok)
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;

};

void printlist(struct Node **head)
{  struct Node *temp = *head;


  while (temp != NULL)
  {
     printf(" %d ", temp->data);
     temp = temp->next;
  }

}


void push(struct Node **head, int value ){

struct Node *newNode = new Node;
newNode->data=value;
newNode->next=*head;
*head=newNode;

   
}

bool detectloop(struct Node* head){

    unordered_set<Node*>s;
  
    while(head!=NULL){
      
        if(s.find(head)!=s.end())
        return true;
      
      
        s.insert(head);
        head=head->next;
    }
    return false;
}

int main(){

struct Node *head = 0;

push(&head, 10);
push(&head, 20);
push(&head, 30);
push(&head, 40);
push(&head, 50);

/* Create a loop for testing */
head->next->next->next->next = head;

//printlist(&head);

if(detectloop(head))
cout<<"Loop found";
else
cout<<"Loop not found";
return 0;

}






