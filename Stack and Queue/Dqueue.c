#include <stdio.h>
#include <stdlib.h>   // All codes are written by me @Akash Ghosh
/*
Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. They are similar to vectors, but are more efficient in case of insertion and deletion of elements. Unlike vectors, contiguous storage allocation may not be guaranteed. 
Double Ended Queues are basically an implementation of the data structure double-ended queue. A queue data structure allows insertion only at the end and deletion from the front. This is like a queue in real life, wherein people are removed from the front and added at the back. Double-ended queues are a special case of queues where insertion and deletion operations are possible at both the ends.
The functions for deque are same as vector, with an addition of push and pop operations for both front and back.  

The time complexities for doing various operations on deques are-

Accessing Elements- O(1)
Insertion or removal of elements- O(N)
Insertion or removal of elements at start or end- O(1)
*/


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

// AG
