#include<iostream>
#include<mpi.h>
#include<math.h>
using namespace std;
float sum;
int x=2;

float factorial(float val){
	
	if(val ==0){
		return 1;
	}
	
for(int i=val-1;i>=1;i--){
val = val*i;

}

return val;

}


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

 
 for(int i=node;i<=99;i=i+size){	
 
 sum = sum + (pow(x,i))/factorial(i);
 
 }
 cout<<node<<": "<<"sum: "<<sum<<endl; 
 
 
if(node<size-1){
 MPI_Send(&sum, 1, MPI_FLOAT, node+1, 0, MPI_COMM_WORLD);
}
 
  
MPI_Finalize();
return 0;
}
