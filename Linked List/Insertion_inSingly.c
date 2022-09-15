#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;

};

//  
void printlist(struct Node *node, int count)
{  
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  printf("\nLength of the list is : %d \n", count);
}

void insert_atbegin(struct Node **head,int count){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for beginning : ");
    scanf("%d", &newNode -> data);
    newNode -> next = *head;
    *head = newNode;
    printf("Node inserted at begining");
    count++;
    printf("\nNew list is :");
    printlist(*head, count);
}

void insert_atend(struct Node **head,int count){
   struct Node *newNode , *temp = *head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for end: ");
    scanf("%d", &newNode -> data);
    newNode -> next = 0; // last node will point to null

    // Traverse to the last node
    while(temp -> next != 0){
        temp = temp -> next;
    }
    
    temp -> next = newNode;

    printf("Node inserted at end");
    count++;
    printf("\nNew list is :");
    printlist(*head,count);
}

void insert_atpos(struct Node **head, int count){

int pos;
printf("Enter position : ");
scanf("%d", &pos);

if(pos > count || pos < 1){
    printf(" Invalid position ");
}
else if( pos ==1){
    insert_atbegin(head,count);
}
else if( pos == count){
    insert_atend(head,count);
}
else{

    struct Node *newNode , *temp = *head;
    int countertemp = 1;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for position %d : ", pos);
    scanf("%d", &newNode -> data);
    while(countertemp < pos-1){
        temp = temp -> next;
        countertemp++;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    printf("Node inserted at position %d", pos);
    count++;
    printf("\nNew list is :");
    printlist(*head,count);

}
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
printlist(head,count);

int insert_choice = 0;
printf("\nDo you want to insert node (0/1)? :");
scanf("%d", &insert_choice);
while(insert_choice){
int ins = 0;
printf("\nEnter 1 to insert at begining, 2 to insert at end, 3 to insert at position : ");
scanf("%d", &ins);
 if(ins == 1){
    insert_atbegin(&head,count);
}
else if(ins == 2){
    insert_atend(&head,count);
}
else if(ins == 3){
    insert_atpos(&head, count);
}
else{
    printf("Invalid choice");
}
printf("\nDo you want to insert node again (0/1) ? :");
scanf("%d", &insert_choice);
}



return 0;
}