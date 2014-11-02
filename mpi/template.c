/**/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"mpi.h"

int main(int argc, char** argv)
{
	int myid,numprocs;
	MPI_Comm comm;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_dup(MPI_COMM_WORLD, &comm);

	/*Main work here*/


	MPI_Finalize();
	return 0;
}
