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
int a;
if(node == 1){
	cin.ignore(); 
cin>>a; 
}

MPI_Bcast(&a, 1, MPI_INT, 1, MPI_COMM_WORLD);
cout<<node<<" "<<a <<endl;
MPI_Finalize();
return 0;
}

