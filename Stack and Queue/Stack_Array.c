#include <stdio.h> 
#include <conio.h>

#define N 5
int top = -1;
int stack[N];  // Stack in from of Array


void push(){
    int x;

    if(top == N-1){
        printf("Stack Overflow\n");
    }
    else{

    printf("Enter element to push: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;

    }
}


void pop(){

int item;

 if(top == -1){
    printf("Stack Underflow\n");
 }
 else{
    item = stack[top];
    top--;
    printf("Popped Element is: %d\n", item);
}

}


void peek(){

if(top == -1)
printf("Stack Underflow\n");
else
printf("Top most element in  the stack is : %d \n", stack[top]);

}

void display(){
    printf(" ELements in the stack is: ");
    for(int i = top; i>=0;i--){
        printf("%d, ",stack[i]);
    }
    printf("\n");
}

int main(){
int ch=0;


do{
    printf("Enter 1 for push , 2 for pop , 3 for peek, 4 for display, 0 to Quit: ") ;
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
