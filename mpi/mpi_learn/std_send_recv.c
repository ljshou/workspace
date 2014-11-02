#include"mpi.h"
#include<stdio.h>
#include<math.h>

#define buf_size 10
int main(int argc, char** argv)
{
	int myid,numprocs,other, sb[buf_size], rb[buf_size];
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

	/*Main work here*/
	for(int i=0; i<buf_size; i++)
	{
		sb[i]=myid+i;
	}
	if(myid==0) other=1;
	if(myid==1) other=0;
	if(myid==0){
	   fprintf(stderr,"process :%d of %d trying sending...\n", myid, numprocs);
	   MPI_Send(sb,buf_size, MPI_INT, other, 1, MPI_COMM_WORLD);
	   fprintf(stderr,"process :%d of %d trying receving...\n", myid, numprocs);
	   MPI_Recv(rb,buf_size, MPI_INT, other, 1, MPI_COMM_WORLD,&status);
	}
	if(myid==1){
	   fprintf(stderr,"process :%d of %d trying receving...\n", myid, numprocs);
	   MPI_Recv(rb,buf_size, MPI_INT, other, 1, MPI_COMM_WORLD,&status);
	   fprintf(stderr,"process :%d of %d trying sending...\n", myid, numprocs);
	   MPI_Send(sb,buf_size, MPI_INT, other, 1, MPI_COMM_WORLD);
	}
	fprintf(stderr, "hello world! Process %d of %d \n", myid, numprocs);

	MPI_Finalize();
	return 0;
}
