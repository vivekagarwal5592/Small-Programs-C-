 #include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char** argv)
{
int size, node, value;
MPI_Status status;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size); 

	if(node==0){
		cout<<node<< " :Hello World"<<endl;
	}

else if(node>0){
		MPI_Recv(&value, 1, MPI_FLOAT, node-1, 0, MPI_COMM_WORLD, &status);
		cout<<node<<" :Hello World"<<endl;
	}

if(node <size-1){
		MPI_Send(&value, 1, MPI_FLOAT, node+1, 0, MPI_COMM_WORLD );
		
}

MPI_Finalize();
return 0;
}
