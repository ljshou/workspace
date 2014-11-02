/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "mpi.h"

int main( int argc, char *argv[] )
{
    int iam, nrows, totals, key ,color;
    int np;
    int colid, rowid;
    MPI_Comm comm, rowcom, colcom, totcom;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &iam);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_dup(MPI_COMM_WORLD, &comm);
/*MAIN work here */
/*Get row and column communicators*/
    nrows = sqrt(np+0.001); //double sqrt(double) e.g. sqrt(10+0.001)赋值给整型得到的是3
 
    totals = nrows*nrows;  //离np最近的完全平方数
    key = iam;
    if ( iam < totals ) color = 1;
    else 
	color = MPI_UNDEFINED;  //把多余的进程color定为MPI_UNDEFINED
    MPI_Comm_split( comm, color, key, &totcom );
    if ( totcom != MPI_COMM_NULL ) {
   	 color = iam / nrows;
    	MPI_Comm_split( totcom, color, key, &rowcom );
    	color = iam % nrows;
    	MPI_Comm_split( totcom, color, key, &colcom );
    	MPI_Comm_rank( rowcom, &colid );
    	MPI_Comm_rank( colcom, &rowid );
    	printf("\n(%d, %d), original id=%d\n", rowid, colid, iam );
     }

    //printf( "Hello world from process %d of %d\n", iam, size );
    MPI_Finalize();
    return 0;
}
