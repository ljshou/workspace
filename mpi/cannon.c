#include <math.h>
#include<stdio.h>
#include<stdlib.h>

#include "mpi.h"

#define msize 100

void inita( int, int, int lda, float[][lda], int, int, int, \
            int*, int* );
void initb( int, int, int lda, float[][lda], int, int, int, \
            int*, int* );
void arowvec( int, int, MPI_Datatype * );
void matcopy( int, int, int lda, float[][lda], int ldb, float[][ldb] );
void matxmat( int lda, float[][lda], int ldb, float[][ldb], int ldc,\
              float[][ldc], int, int, int );
void initc( int ldc, float[][ldc], int, int );

/*8888888888888888888888888888888888888888888888888888888888888888888
  8888888888888888888888888888888888888888888888888888888888888888888*/
/*Start the main program*/
void main(argc, argv)
int argc; char **argv;
{
  int iam, np;
  MPI_Comm comm;
  int nrows, totals, key, color, rowid, colid;
  MPI_Comm totcom, rowcom, colcom;
  float a[50][50], ta[50][50], b[50][50], c[50][50];
  int m, k, n, lm, lk, ln, lda, ldb, ldc, *npt, ncc, ncr, root, up, down, i;
  MPI_Datatype vecta, vectb;
  MPI_Status st;

/*The matrix A is size of MxN, B is NxK*/
/* mybegin( argc, argv, &comm, &iam, &np );*/
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &iam);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_dup(MPI_COMM_WORLD, &comm);
/*MAIN work here */
/*Get row and column communicators*/
  m = 10;
  n = 9;
  k = 6;
  lda = 50;
  ldb=lda;
  ldc=lda;
  nrows = sqrt(np+0.001);
 
  totals = nrows*nrows;
  key = iam;
  if ( iam < totals ) color = 1;
  else color = MPI_UNDEFINED;
  MPI_Comm_split( comm, color, key, &totcom );
  if ( totcom != MPI_COMM_NULL ) {
    color = iam / nrows;
    MPI_Comm_split( totcom, color, key, &rowcom );
    color = iam % nrows;
    MPI_Comm_split( totcom, color, key, &colcom );

    MPI_Comm_rank( rowcom, &colid );  //进程iam在列通信子中的id
    MPI_Comm_rank( colcom, &rowid );  //进程iam在行通信子中的id
    printf("\n(%d, %d), original id=%d\n", rowid, colid, iam );

/*finish communicators*/
    initb( n, k, ldb, b, rowid, colid, nrows, &ln, &lk );
    inita( m, n, lda, a, rowid, colid, nrows, &lm, &ln );
    initc( ldc, c, lm, lk );

/*
    npt = (int *)malloc(nrows*sizeof(int));
    MPI_Allgather(&ln, 1, MPI_INT, npt, 1, MPI_INT, rowcom);
    
    ncr = npt[0];
    arowvec( ncr, lda, &vecta );
    arowvec( lk, ldb, &vectb );
    up = (rowid - 1 + nrows) % nrows;
    down = (rowid + 1) % nrows;
    for( i=0; i<nrows; i++) {
      root = (rowid + i) % nrows;
      if( colid == root )
        matcopy( lm, ln, lda, a, lda, ta );
      MPI_Bcast(ta, lm, vecta, root, rowcom );
      ncc = npt[root];
      matxmat(lda, ta, ldb, b, ldc, c, lm, ncc, lk );
      if( i == nrows-1 ) continue;
      MPI_Sendrecv(b, ncc, vectb, up, 1, ta, ncr, vectb, down, 1, colcom, &st); 
      matcopy( ncr, lk, lda, ta, ldb, b );
    }
    printf("\nValue of c[0][0]=%f on (%d, %d)", c[0][0], rowid, colid);
*/
  }

/*computation finished*/
  MPI_Finalize( );
}

void arowvec(int blk,int strd,MPI_Datatype* vect )
{
  int blen[2], dspls[2];
  MPI_Datatype con, dt[2];

  MPI_Type_contiguous( blk, MPI_FLOAT, &con );
  blen[0]=1;
  blen[1]=1;
  dspls[0]=0;
  dspls[1]=strd*sizeof(float);
  dt[0]= con;
  dt[1]= MPI_UB;
  MPI_Type_struct(2, blen, dspls, dt, vect);
}


/*mXn, a_ij=i+j, b_ij = 1.0-((i+j)%2)*2.0*/
/*N[i]=n/p in process i*/

void inita( m, n, lda, a, rowid, colid, nrows, lm, ln )
int m, n, lda, rowid, colid, nrows, *lm, *ln;
float a[][lda];
{
  int i, j, *nblk, tn, ts, tt;
  nblk = (int *)malloc(nrows*sizeof(int));
  tn = m / nrows;
  for(i=0; i<nrows; i++) {
    if(i<(m%nrows)) 
      nblk[i] = tn+1;
    else 
      nblk[i] = tn;
  }
  if ( rowid < (m % nrows) ) tn++;
  *lm = tn;
  ts = 0;
  for(i=0; i<rowid; i++) ts += nblk[i];

  tn = n / nrows;
  for(i=0; i<nrows; i++) {
    if(i<(n%nrows)) 
      nblk[i] = tn+1;
    else 
      nblk[i] = tn;
  }
  if ( colid < (n%nrows) ) tn++;
  *ln = tn;
  tt = 0;
  for(i=0; i<colid; i++) tt += nblk[i];

  for( i=0; i<*lm; i++ )
    for( j=0; j<*ln; j++ ){
      a[i][j] = i+j+ts+tt;
    }
  free( nblk );
}

void initb( m, n, lda, a, rowid, colid, nrows, lm, ln )
int m, n, lda, rowid, colid, nrows, *lm, *ln;
float a[][lda];
{
  int i, j, *nblk, tn, ts, tt;
  nblk = (int *)malloc(nrows*sizeof(int));
  tn = m / nrows;
  for(i=0; i<nrows; i++) {
    if(i<(m%nrows)) 
      nblk[i] = tn+1;
    else 
      nblk[i] = tn;
  }
  if ( rowid < (m%nrows) ) tn++;
  *lm = tn;
  ts = 0;
  for(i=0; i<rowid; i++) ts += nblk[i];

  tn = n / nrows;
  for(i=0; i<nrows; i++) {
    if(i<(n%nrows)) 
      nblk[i] = tn+1;
    else 
      nblk[i] = tn;
  }
  if ( colid < (n%nrows) ) tn++;
  *ln = tn;
  tt = 0;
  for(i=0; i<colid; i++) tt += nblk[i];

  for( i=0; i<*lm; i++ )
    for( j=0; j<*ln; j++ ){
      a[i][j] = 1.0-((i+j+ts+tt)%2)*2.0;
    }
  free( nblk );
}

/*矩阵复制 COPY a[m][n] TO b[][ldb] */
void matcopy( m, n, lda, a, ldb, b )
int m, n, lda, ldb;
float a[][lda], b[][ldb];
{
  int i;
  for (i=0; i<m; i++)
    memcpy(&b[i], &a[i], n*sizeof(float));
}

/*矩阵C[m][n] 初始化*/
void initc( ldc, c, m, n )
int ldc, m, n;
float c[][ldc];
{
  int i, j;

  for( i=0; i<m; i++ )
    for( j=0; j<n; j++ ) 
      c[i][j] = 0.0;
}
/*matrix A is MxN, B is NxL, C is MxL*/
/*子矩阵块相乘*/
void matxmat( lda, a, ldb, b, ldc, c, m, n, l )
int lda, ldb, ldc, m, n, l;
float a[][lda], b[][ldb], c[][ldc];
{
  int i, j, k;
  float s;

  for( i=0; i<m; i++ )
    for( j=0; j<l; j++ ) {
      s = 0.0;
      for( k=0; k<n; k++ )
        s += a[i][k]*b[k][j];
      c[i][j] += s;
    }
}
