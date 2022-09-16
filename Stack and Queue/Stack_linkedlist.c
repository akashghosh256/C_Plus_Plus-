#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *link;

};

struct Node *top = 0;

void push()
{   int x;
    printf("Enter element to push: ");
    scanf("%d", &x);

    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = x;
    newnode -> link = top;
    top = newnode;
}

void display(){
struct Node *temp;
temp = top;
if(top == 0){
    printf("Stack is Empty");
}
else{
    printf(" ELements in the stack is: ");
    while(temp != 0){
        printf("%d, ", temp -> data);
        temp = temp -> link;

    }
  //  printf("\n");
}
}

void peek(){
    
    if(top == 0){
        printf("Stack is Empty");
    }
    else{
        printf("Top element is: %d ", top -> data);
    }
}

void pop(){
    struct Node *temp;
    temp = top;
    if(top == 0){
        printf("List is Empty");
    }
    else{
        printf("Pop data is: %d\n", top ->data);
        top = top -> link;
        free(temp);
        
    }
}

int main(){

int ch=0;


do{
    printf("\nEnter 1 for push , 2 for pop , 3 for peek, 4 for display, 0 to Quit: ") ;
    scanf("%d", &ch);

    switch(ch)
{   case 0: printf("Quitting");
        break;
    case 1: push();
        break;
    case 2: pop();
        break;
    case 3: peek();
        break;
    case 4: display();
        break;
    default:
    printf(" Wrong Choice\n");


}


}
while(ch!=0);

}
