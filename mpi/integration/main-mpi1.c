/* $Id: main-mpi1.c,v 1.2 2005/06/20 03:28:52 zlb Exp $ */

/* 递归方式自适应数值积分MPI主程序：均匀区间划分 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mpi.h"
#include "integration.h"
#include "function.h"

int
main(int argc, char **argv)
{
    int nprocs, myrank;
    double a = 0.0, b = 1.0;
    double eps, res0, res, a0, b0, cpu0, cpu1, wall0, wall1, wall2;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0) {
	if (argc != 2) {
	    fprintf(stderr, "Usage:   %s epsilon\n", argv[0]);
	    fprintf(stderr, "Example: %s 1e-4\n", argv[0]);
	    MPI_Abort(MPI_COMM_WORLD, 1);
	    return 1;
	}
	eps = atof(argv[1]); //将命令中的 误差转换为 double 赋值给 eps
    }

    /* 将 eps 广播给所有进程 */
    MPI_Bcast(&eps, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);  // 0 表示root进程是0进程

    /* 计算本进程的积分区间 [a0, b0] */
    a0 = a + (myrank + 0) * (b - a) / nprocs;
    b0 = a + (myrank + 1) * (b - a) / nprocs;

    /* 开始时间 */
    gettime(&cpu0, &wall0);
    res0 = integration(a0, F(a0), b0, F(b0), eps / (b - a), F);
    gettime(&cpu1, &wall1);
    printf("\tRank=%d, # of evaluations=%u, cputime=%0.4lf, wtime=%0.4lf\n",
	   myrank, evaluation_count, cpu1 - cpu0, wall1 - wall0);
    MPI_Reduce(&res0, &res, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    gettime(NULL, &wall2);
    if (myrank == 0) {
	printf("result=%0.16lf, error=%0.4le, wtime=%0.4lf\n",
		res, res - RESULT, wall2 - wall0);
    }

    MPI_Finalize();
    return 0;
}
