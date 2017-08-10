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
float val,b=0;

 if(node !=8){
	val = 5;
	MPI_Send(&val, 1, MPI_FLOAT, 8, 0, MPI_COMM_WORLD );
}

else
{
	val =0;
	int i=0;
	while(i<8){
		MPI_Recv(&b, 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD, &status);
		val = val +b;
		i++;
	}
	cout<<node<<" "<<val<<endl;
}


MPI_Finalize();
return 0;
}
