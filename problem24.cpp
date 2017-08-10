#include<iostream>
#include<mpi.h>
using namespace std;
float sum=0;
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;

MPI_Init(&argc, &argv); 
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
 

 
 if(node>0){
 	 MPI_Recv(&sum, 1, MPI_FLOAT, node-1, 0, MPI_COMM_WORLD, &status);
 }

 float x=0.02;
 for(int i=node;x*i<=1;i=i+size)	{
 
 sum = sum+(1/(1+(x*i)*(x*i)));
// cout<<"i am here";
}
 cout<<node<<": "<<"sum: "<<sum<<endl; 
 
 
if(node<size-1){
 MPI_Send(&sum, 1, MPI_FLOAT, node+1, 0, MPI_COMM_WORLD);
}
 
 
 
 
  
MPI_Finalize();
return 0;
}
