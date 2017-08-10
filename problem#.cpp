#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char** argv)
{
int size, node;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node); 
MPI_Comm_size(MPI_COMM_WORLD, &size); 
int a=3;
MPI_Bcast(&a, 1, MPI_INT, 0, MPI_COMM_WORLD);
cout<<node<<" " <<a<<endl;
return 0;
}
