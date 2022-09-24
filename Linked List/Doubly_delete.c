#include <stdio.h>
#include <stdlib.h>

// Implementing a Doubly linked list works both C/C++ with no errors (fully same, no change required)

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;

};
struct Node *head , *newnode, *tail;
int count = 0;

void deletefrom_beg(){
    if(head == 0){
        printf("List is already empty\n");
    }
    else{
    struct Node *temp;
    temp =head;
    head = temp -> next;
    head -> prev = NULL;
    free(temp);
    printf("Deleted from beg\n");
    count--;
}
}
void deletefrom_end(){
     if(head == 0){
        printf("List is already empty\n");
    }
    else{
    struct Node *temp;
    temp = tail;
    tail = temp -> prev;
    tail -> next = NULL;
    free(temp);
    printf("Deleted from end\n");
    count--;
}
}

void deletefrom_pos(){
     if(head == 0){
        printf("List is already empty\n");
    }
    else{
    int pos,count =0;
    printf("Enter pos for delete");
    scanf("%d",&pos);
    if(pos == 1) deletefrom_beg;
    else if(pos == count) deletefrom_end;
    else{
    struct Node *temp;
    temp =head;
    int count = 1;

    while(count < pos ){
        temp = temp -> next;
    }

    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
    count--;
    printf("Deleted from pos\n");
}
}
}

void insertatbeg(){
struct Node *newnode;
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("enter data: ");
scanf("%d", &newnode -> data);
newnode -> prev = 0;
newnode -> next = 0;
head -> prev = newnode;
newnode -> next = head;
head = newnode;
count++;
}

void insertatend(){
struct Node *newnode;
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("enter data: ");
scanf("%d", &newnode -> data);
newnode -> prev = 0;
newnode -> next = 0;

tail -> next = newnode;
newnode -> prev = tail;
tail = newnode;
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
newnode -> prev = 0;
newnode -> next = 0;
 temp = head;
int check = 1;
while(check <pos -1){
    temp = temp -> next;
    check++;
  }

newnode -> next = temp -> next;
newnode -> prev = temp;
temp -> next = newnode;
newnode -> next -> prev = newnode;
count++;

}
}



void display(){
    printf("No of element in list is: %d ", count);

    printf("\nCrerated  LL is :");
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
    head = tail = temp = newnode;
}
else{
    temp -> next = newnode ;
    newnode -> prev = temp;   
    temp = newnode;
    tail = newnode;
}
count++;
printf("\nDO you want to continue (0/1): ");
scanf("%d", &choice );

}


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

do{
printf("Do u want to delete(0/1)");
scanf("%d",&ch);
if(ch){
    int pos;
    printf("Enter 1 for beg , 2 for end , 3 for pos  & 0 for QUIT ");
    scanf("%d", &pos);
    if(pos == 1) deletefrom_beg();
    else if(pos == 2) deletefrom_end();
    else if(pos == 3) deletefrom_pos();
    else ch = 0;
}
}while(ch);

display();

}