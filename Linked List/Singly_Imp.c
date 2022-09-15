#include <stdio.h>
#include <stdlib.h>

// Implementing a singly linked list works both C/C++ with no errors (fully same, no change required)

struct Node{
    int data;
    struct Node *next;

};

void printlist(struct Node *node)
{  
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

int main(){


struct Node * head = 0, *temp , *newNode;
int choice = 1;

while(choice){
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d", &newNode -> data);
    newNode -> next = 0;

    if( head == 0){
        head = temp = newNode;

    }
    else{
         temp -> next = newNode;
         temp = newNode;
    }
printf("Do you want to continue (0,1)?");
scanf("%d", &choice);
}
printf("Crerated  LL is :");
printlist(head);
return 0;
}