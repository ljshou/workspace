/*deadlock*/
#include"mpi.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv)
{
	int myid,numprocs;
	MPI_Status status;
	int rb=0,sb=0,tag=123,count=1;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

	/*Main work here*/
	if(myid==0)
	{
		MPI_Recv(&rb,count,MPI_INT,1,tag,MPI_COMM_WORLD,&status);
		MPI_Send(&sb,count,MPI_INT,1,tag,MPI_COMM_WORLD);
	}
	if(myid==1)
	{
		MPI_Recv(&rb,count,MPI_INT,0,tag,MPI_COMM_WORLD,&status);
		MPI_Send(&sb,count,MPI_INT,0,tag,MPI_COMM_WORLD);
	}


	MPI_Finalize();
	return 0;
}
