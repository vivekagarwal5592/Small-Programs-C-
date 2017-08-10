#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char** argv)
{
MPI_Status status;
int size, node;
int a,b;
MPI_Init(&argc, &argv); MPI_Comm_rank(MPI_COMM_WORLD, &node); MPI_Comm_size(MPI_COMM_WORLD, &size); 
if(node == 0)
{
a=1; b=2;
MPI_Recv(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
MPI_Send(&b, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
}
else
{
 a=101; b=102;
MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
MPI_Send(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
}
cout<<node<<" " <<a<<" "<<b<<endl;
MPI_Finalize();
}
