#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char** argv)
{
int size, node;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size); 
int a=0,b=0;
if(node == 1)
MPI_Recv(&b, 1, MPI_INT, node-1, 0, MPI_COMM_WORLD, &status);
else
if(node == 0)
{
a=3;
MPI_Send(&a, 1, MPI_INT, node+1, 0, MPI_COMM_WORLD);
}cout<<node<<" " <<a<<" "<<b<<endl;MPI_Finalize();
return 0;
}
