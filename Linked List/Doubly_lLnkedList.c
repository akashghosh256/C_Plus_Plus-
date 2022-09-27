#include <stdio.h>
#include <stdlib.h>

// Implementing a Doubly linked list works both C/C++ with no errors (fully same, no change required)

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;

};
struct Node *head , *newnode;

void display(){
    printf("Crerated  LL is :");
    struct Node *temp;
    temp = head;
     while(temp!=0){
        printf("%d, ", temp -> data);
        temp = temp -> next;
     }
}
void create(){
head = 0;
struct Node *temp;
int choice = 1;

while(choice){
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("enter data: ");
scanf("%d", &newnode -> data);
newnode -> prev = 0;
newnode -> next = 0;
if(head == 0 ){
    head = temp = newnode;
}
else{
    temp -> next = newnode ;
    newnode -> prev = temp;   
    temp = newnode;
}
printf("\nDO you want to continue (0/1): ");
scanf("%d", &choice );
}
display();

}



int main(){
create();

}
