#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

void main(int argc,char** argv)
{
	int iam, np;
	MPI_Comm comm;

	MPI_Init( &argc, &argv);
	MPI_Comm_dup( MPI_COMM_WORLD, &comm );
	MPI_Comm_rank( comm, &iam );
	MPI_Comm_size( comm, &np);
	/*Main work here*/
	printf("\nHello world from Proc. %d\n", iam);
	MPI_Finalize();
}

