/*test*/
#include"mpi.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	int myid,numprocs;
	MPI_Status status1,status;
	MPI_Request r1,r2;
	int rba=0,rbb=0,sba=1,sbb=2,tag=123,count=1;


	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

	/*Main work here*/
	if(myid==0)
	{
		MPI_Ssend(&sba,count,MPI_INT,1,0,MPI_COMM_WORLD);
		MPI_Send(&sbb,count,MPI_INT,1,1,MPI_COMM_WORLD);
	}
	if(myid==1)
	{
		MPI_Irecv(&rba,count,MPI_INT,0,1,MPI_COMM_WORLD,&r1);
		MPI_Recv(&rbb,count,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		MPI_Wait(&r1,&status);
	}
	MPI_Finalize();
	return 0;
}
