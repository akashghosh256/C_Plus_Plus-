#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;

};



void printlist(struct Node *node, int count)
{  
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  printf("\nLength of the list is : %d \n", count);
}



void delete_fromstart(struct Node **head , int count){
    struct Node *temp = *head;
if(temp -> next != NULL){
*head = temp -> next;
free(temp);
printf("Deleted from start : ");
count--;
printlist(*head,count);
}
else{
    printf("List is empty");
}
}

void delete_fromend(struct Node **head, int count){
    struct Node *prevnode , *temp = *head;
    while(temp -> next != NULL){
        prevnode = temp;
        temp = temp -> next;
    }

    if(temp == *head){
        printf("List has only one node/n");
        head = 0;
    }
    else{
        prevnode -> next = 0;
        free(temp);
    }
    printf("Deleted from  end ");
    count--;
    printlist(*head,count);
}

void delete_frompos(struct Node **head, int count){
    struct Node *deletenode, *temp = *head ;
    int pos , i=1;
    printf("Enter position : ");
    scanf("%d", &pos);

if(pos == 1 ){
    delete_fromstart(head,count);
}
else if(pos == count){
    delete_fromend(head,count);
}
else{
    while(temp -> next != NULL && i < pos-1){
        temp = temp -> next;
        i++;
    }

    deletenode = temp -> next;
    temp -> next = deletenode -> next ;
    free(deletenode);

     printf("Deleted from position %d",pos);
    count--;
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
printf("\nDo you want to delete node (0/1)? :");
scanf("%d", &insert_choice);
while(insert_choice){
int ins = 0;
printf("\nEnter 1 to delete at begining, 2 to delete at end, 3 to delete at position : ");
scanf("%d", &ins);

 if(ins == 1){
    delete_fromstart(&head,count);
}
else if(ins == 2){
    delete_fromend(&head,count);
}
else if(ins == 3){
    delete_frompos(&head,count);
}
else{
    printf("Invalid choice");
}
printf("\nDo you want to delete node again (0/1) ? :");
scanf("%d", &insert_choice);
}



return 0;
}