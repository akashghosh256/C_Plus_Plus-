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
        printf("%d \n", temp -> data);  // To print the last element because loop will stop before it !
}


void insertatbeg(){
struct Node *newnode;
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("enter data: ");
scanf("%d", &newnode -> data);
if(tail == 0 ){
    tail = newnode;
    tail -> next = newnode;
}
else{
newnode -> next = tail -> next;
tail -> next = newnode;
}
count++;
}


void insertatend(){
struct Node *newnode;
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("enter data: ");
scanf("%d", &newnode -> data);
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

}

void insertatpos(){
int pos;
printf("Enter POSITION of insertion: ");
scanf("%d", &pos);
if(pos < 1 || pos> count){
    printf("invalid position! Try aGAIN /n  ");
}
 else if (pos ==1 ){
    insertatbeg();
 }
else if(pos== count){
    insertatend();

}
else{
struct Node *newnode, *temp;
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("enter data: ");
scanf("%d", &newnode -> data);
 temp = tail -> next;
int check = 1;
while(check <pos -1){
    temp = temp -> next;
    check++;
  }
newnode -> next = temp -> next;
temp -> next = newnode;

count++;

}
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
int ch = 0;
do{
printf("Do u want to insert(0/1)");
scanf("%d",&ch);
if(ch){
    int pos;
    printf("Enter 1 for beg , 2 for end , 3 for pos  & 0 for QUIT ");
    scanf("%d", &pos);
    if(pos == 1) insertatbeg();
    else if(pos == 2) insertatend();
    else if(pos == 3) insertatpos();
    else ch = 0;
}
}while(ch);

display();

}