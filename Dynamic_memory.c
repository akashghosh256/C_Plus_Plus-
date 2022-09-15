#include <stdio.h>
#include <stdlib.h>
//---------------------- Dynamic memory allocation in C - malloc calloc realloc free --------------------------------

int main(){
    int n ;
    printf ( "Enter  size of array: " ) ;
    //scanf ( "%d" , &n ) ;
    n=5;
    int *A = (int*) malloc(n *sizeof(int) );        // dynamically allocated array using malloc
    int *B = (int*) calloc(n, sizeof(int) );        // dynamically allocated array using calloc


printf("\nDefault or garbage values of Malloc in A:");
for ( int i = 0 ; i < n ; i ++ )
    {
        printf ( " %d " , A[ i ] ) ;
    }

printf("\nDefault values of Calloc in B:");
for ( int i = 0 ; i < n ; i ++ )
    {
        printf ( " %d " , B[ i ] ) ;
    }

  // Just putting values in array A 
    for ( int i=0; i<n ; i ++ )
    {
        A [i] = i + 1 ;
   }
   int NUmber_of_new_elements = 3;
   int *C = (int *) realloc ( A , (NUmber_of_new_elements) * sizeof (int) ) ;  // reallocating memory to array A
   //int *C = (int *) realloc ( NULL, (NUmber_of_new_elements) * sizeof (int) ) ;  // EQUIVALENT TO MALLOC
   printf ( "\nPrev block address % d , new address = % d \n " , A , C ) ;
   
   // Putting values in new memory block by referencing ( or using pointer)
   *(A+6)=20;
   *(A+7)=40;
   *(A+5)=60;

printf("\nValues After putting values in A after using realloc too:");
 for ( int i = 0 ; i < n+3 ; i ++ )
    {
        printf ( " %d " , A [ i ] ) ;
    }
   
  
free (A) ;
 A = NULL ; // After free , adjust pointer to NULL
printf("Values after freeing A:");
for ( int i = 0 ; i < n+3 ; i ++ )
    {
        printf ( " %d " , A [ i ] ) ;
    }
// It might still show values of old values stored in A but it is free to store any new values in place of it
    
}