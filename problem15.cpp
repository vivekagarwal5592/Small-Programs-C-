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
int a=0,b=0,c=0;
if(node == 1){
a =3;
b=4;
c=a+b;
MPI_Send(&c, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
}


else
if(node == 0)
{
a=1;
b=2;
MPI_Recv(&c, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
c= c+a+b;
cout<<node<<" total sum: " <<c<<endl;
}

MPI_Finalize();
return 0;
}
