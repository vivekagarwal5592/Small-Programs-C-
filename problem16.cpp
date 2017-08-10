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
float value=0;
if(node == 8)
{
	value=10;
	for(int i=0;i<8;i++){
		MPI_Send(&value, 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD );
	}
}

else{
MPI_Recv(&value, 1, MPI_FLOAT, 8, 0, MPI_COMM_WORLD, &status);
}
cout<<"node:"<<node<<" value:" <<value<<endl;
MPI_Finalize();
return 0;
}
