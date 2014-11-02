//ssendrecv.c
#include"mpi.h"
#include<stdio.h>

int main(int argc, char **argv)
{
	int rank, size,i;
	int buffer[10];
	MPI_Status status;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("size=%d\n", size);
	if(size<2)
	{
		printf("Please run with two processes. \n");
		fflush(stdout);
		MPI_Finalize();
		return 0;
	}
	/*Main work here*/
	if(rank==0)
	{
	   for(i=0;i<10;i++)
	      buffer[i]=i;
	   printf("proc:%d sending\n",rank);
	   MPI_Ssend(buffer,10,MPI_INT,1,123,MPI_COMM_WORLD);
	} 
	if(rank==1)
	{
	   for(i=0;i<10;i++)
              buffer[i]=-1;
	   printf("proc:%d receiving\n",rank);
	   MPI_Recv(buffer,10,MPI_INT,0,123,MPI_COMM_WORLD,&status);
	   for(i=0;i<10;i++)
	   {
		if(buffer[i]!=i)
			printf("error: buffer[%d]=%d, but expected to be %d\n",i,buffer[i],i);
	   }
	   for(i=0;i<10;i++)
	   {
		printf("%d: buffer[%d]=%d, expected to be %d\n",rank,i,buffer[i],i);
	   }
	   fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}
		
