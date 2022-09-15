#include <stdio.h>
#include <stdlib.h>


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

void reverse(struct Node **head){
    struct Node *prevnode , *currentnode , *nextnode;
    prevnode = 0;
    currentnode = nextnode = *head;
    while(nextnode != 0){
        nextnode = nextnode -> next;
        currentnode -> next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
*head = prevnode;
printf("\nReversed list is : ");
printlist(*head);

}

int main(){


struct Node *head = 0, *temp , *newNode;
int choice = 1, count = 0;

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
count++;
printf("Do you want to continue (0,1)?");
scanf("%d", &choice);
}
printf("Crerated  LL is :");
printlist(head);
reverse(&head);
}
