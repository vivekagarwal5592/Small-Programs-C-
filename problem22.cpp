#include<iostream>
#include<mpi.h>
using namespace std;
int sum;
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;

MPI_Init(&argc, &argv); 
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
 
 int a[100];
 for(int i=node;i<=99;i=i+size){
 	a[i] = 1;
 //	cout<<a[i];
 }
 
 if(node>0){
 	 MPI_Recv(&sum, 1, MPI_INT, node-1, 0, MPI_COMM_WORLD, &status);
 }

 
 for(int i=node;i<=99;i=i+size){	
 sum = sum+a[i] ;
// cout<<"i am here";
 }
 cout<<node<<": "<<"""sum: "<<sum<<endl; 
 
 
if(node<size-1){
 MPI_Send(&sum, 1, MPI_INT, node+1, 0, MPI_COMM_WORLD);
}
 
 
 
 
  
MPI_Finalize();
return 0;
}
