      program main
      implicit none
      include 'mpif.h'

      integer iam, np, comm, m, n, next, front, tag, 
     &        sta(mpi_status_size), ierr
*
      call MPI_Init( ierr )
      call MPI_Comm_dup( MPI_COMM_WORLD, comm, ierr )
      call MPI_Comm_rank( comm, iam, ierr )
      call MPI_Comm_size( comm, np, ierr )
*
*MAIN work here *
      m = iam
      front = mod(iam-2+np, np)
      next = mod(iam+2, np)
      tag = 1
*
c      if( iam .eq. 0 ) then
c        front = MPI_PROC_NULL 
c        n=100
c      endif
c      if( iam .eq. np-1 ) then
c        next = MPI_PROC_NULL
c      endif
*
      call MPI_Sendrecv(m, 1, MPI_real, next, tag, n, 1, MPI_real, 
     &                  front, tag, comm, sta, ierr )
c
      write(*, *) 'Value=', n, 'on proc ', iam

      call MPI_Finalize(ierr )

      end

