#include <stdio.h>
#include <stdlib.h>

// Implementing a Circular linked list using tail pointer only works both C/C++ with no errors (fully same, no change required)

struct Node{
    int data;
    struct Node *next;

};
struct Node  *tail, *newnode;
int count = 0;

void display(){
    printf("No of Nodes: %d",count);
    printf("\nCrerated  LL is :");
    struct Node *temp;
    temp = tail -> next;

     while(temp -> next != tail -> next){
        printf("%d, ", temp -> data);
        temp = temp -> next;
 
     }
        printf("%d, ", temp -> data);   // To print the last element because loop will stop before it !
}


void create(){
tail = 0;
struct Node *temp;
int choice = 1;

while(choice){
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("enter data: ");
scanf("%d", &newnode -> data);
newnode -> next = 0;

if(tail == 0 ){
    tail = newnode;
    tail -> next = newnode;
}
else{
    newnode -> next = tail -> next;
    tail -> next = newnode;
    tail = newnode;   
  
}
count++;
printf("\nDO you want to continue (0/1): ");
scanf("%d", &choice );
}
display();


}

int main(){
create();

}