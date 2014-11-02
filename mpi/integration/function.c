/* $Id: function.c,v 1.2 2005/06/20 03:28:52 zlb Exp $ */

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int evaluation_count = 0;

/* �������� */
double F(double x)
{
    size_t i;
    for (i = 0; i < 5000000; i++);	/* Ϊ���Ӽ���ʱ������Ŀ�ѭ��\label{function.c:1} */
    evaluation_count++;
    return 4.0 / (1.0 + x * x);		/* $f(x) = \dfrac4{1+x^2}$ */
}

/* ���־�ȷֵ (���ڼ�����) */
double RESULT = 3.141592653589793;

void gettime(double *cpu, double *wall)
/* ���ص�ǰ CPU ��ǽ��ʱ�� */
{
    struct timeval tv;
    struct rusage ru;
    if (cpu != NULL) {
	getrusage(RUSAGE_SELF, &ru);
	*cpu = ru.ru_utime.tv_sec + (double)ru.ru_utime.tv_usec * 1e-6;
    }
    if (wall != NULL) {
	gettimeofday(&tv, NULL);
	*wall = tv.tv_sec + (double)tv.tv_usec * 1e-6;
    }
}
