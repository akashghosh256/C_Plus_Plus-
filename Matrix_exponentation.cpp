/* 
Matrix multiplication for given a power OR 
find  the power of a matrix
*/


#include<bits/stdc++.h>
using namespace std;

#define N 101
int ar[N][N];  int I[N][N];



//      here a = identity marix I[][] and b = main matrix  
void mul(int a[][N], int b[][N], int dim){

int res[dim+1][dim+1];

for(int i=0;i<dim;i++){

    for(int j=0;j<dim;j++){
           res[i][j]=0;
          for(int k=0;k<dim;k++){

            res[i][j] += a[i][k] * b[k][j];

          }
    }
}
for(int i=0;i<dim;i++){
    for(int j=0;j<dim;j++){
        a[i][j]=res[i][j];
}}


}



void calmat(int a[][N],int dim, int p){

// creating the identity matrix I
for(int i=0; i<dim;i++){
    for(int j=0; j<dim;j++){
        if(i==j) I[i][j]=1;
        else I[i][j]=0;
    }
}

/*
for(int i=1;i<=p;i++){
mul(I,a,dim);
}
*/


//

while(p){

if(p%2)
mul(I,a,dim), p--;
 else mul(a,a,dim), p/=2;

}


// putting the new values back to "a" matrix
for(int i=0;i<dim;i++){
    for(int j=0;j<dim;j++)
    a[i][j]=I[i][j];
}




}


void printmatrix(int a[][N], int dim){
// printing the resultant matrix after all calculation 

for(int i=0;i<dim;i++){
    for(int j=0;j<dim;j++){
      cout<<a[i][j]<<" ";
}
cout<<endl;
}
}





int main(){

int t;
 cout<<"Enter t: ";
 cin>>t;

while(t--){


// dim = dimension or size of a matrix and p = power 
int dim,p;
cout<<"Enter dim & p: ";
cin>>dim>>p;

for(int i=0;i<dim;i++){
    for(int j=0;j<dim;j++){
        cin>>ar[i][j];
    }
}
// claculating  new matrix (by calling the function )
calmat(ar,dim,p);

// printing the matrix (by calling the function )
printmatrix(ar, dim);

}


return 0;
}
