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



cout<<node<<" :Hello World"<<endl;
MPI_Finalize();
return 0;
}
