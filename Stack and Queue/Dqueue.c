#include <stdio.h>
#include <stdlib.h>

#define N 5
int deque[N];
int f=-1, r=-1;

void enqueue_front(){ 
    // To enter element from front of the queue
    if((f ==0 && r == N-1)||(f == r+1)){
        printf("\nDqueue is full");
    }
     else{
        int x;
        printf("\nenter data: ");
        scanf("%d",&x);
  
    if(f== -1 && r == -1){
        f = r= 0;
        deque[f]=x;
        printf("\nElement Inserted: %d", x);
    }
    else{
        f--;
        deque[f]=x;
         printf("\nElement Inserted: %d", x);
    }
}
}

void enquer_rear(){
   // To enter element from rear/back of the queue
    if((f ==0 && r == N-1)||(f == r+1)){
        printf("Dqueue is full");
    }
    else{
         int x;
        printf("\nenter data: ");
        scanf("%d",&x);
     if(f== -1 && r == -1){
        f = r = 0;
        deque[f]=x;
        printf("\nElement Inserted: %d", x);
    }
    else{
        r++;
        deque[r]=x;
         printf("\nElement Inserted: %d", x);
    }
}}

void display(){
    int i =f;
    printf("\nElements are: ");
    while(i != r){
        printf("%d, ", deque[i]);
        i = (i+1)%N;
    }
    printf("%d", deque[r]);
}


void get_front(){

    if( f==-1 && r ==-1){
        printf("\nDqueue is empty");
    }
    else{
        printf("front element is: %d",deque[f]);
    }
}

void get_rear(){
  if( f==-1 && r ==-1){
        printf("\nDqueue is empty");
    }
    else{
        printf("front element is: %d",deque[r]);
    }
}


void deque_front(){

    if(f== -1 && r == -1){
        printf("\n Queue is empty");
    }
    else if(f == r ){
        printf("Deleted element is: %d ", deque[f]);
        f =r=-1;
    }
    else if( f == N-1){
        printf("Deleted element is: %d ", deque[f]);
        f=0;
    }
else{
    printf("Deleted element is: %d ", deque[f]);
    f++;
}
}

void deque_rear(){
  if(f== -1 && r == -1){
        printf("\n Queue is empty");
    }
    else if(f == r ){
        printf("Deleted element is: %d ", deque[r]);
        f =r=-1;
    }
    else if( r ==0 ){
        printf("Deleted element is: %d ", deque[r]);
        r = N -1;
    }
else{
    printf("Deleted element is: %d ", deque[r]);
    r--;
}
 }


int main(){

int ch = 1;
do{
if(ch){
    int pos;
    printf("\nEnter 1 for beg , 2 for end , 3 for deque front , 4 for deque rear, 5 for get front , 6 for get rear, 7 for display  & 0 for QUIT:  ");
    scanf("%d", &pos);
    if(pos == 1) enqueue_front();
    else if(pos == 2) enquer_rear();
    else if(pos == 3) deque_front();
    else if(pos == 4) deque_rear();
    else if(pos == 5) get_front();
    else if(pos == 6) get_rear;
    else if(pos == 7) display();

    else ch = 0;
}
}while(ch);



}