/* $Id: integration.c,v 1.3 2005/08/28 12:24:15 zlb Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integration.h"

#define MAX_DEPTH	1024		/* ���ݹ���� */
#define MACHINE_PREC	1e-15		/* �������� */

double
integration(double a, double fa, double b, double fb, double eps,
	  double(*F)(double x))
/* ���ι�ʽ�ݹ�������ֵ */
{
    static int depth = 0;		/* ��ǰ�ݹ���� */
    double fc, v0, v, h, xc;

    ++depth;
    v = 0.0;
    if (a != b) {
	xc = (a + b) * 0.5;
	h = b - a;
	v = v0 = h * (fa + fb) * 0.5;
	if (xc != a && xc != b) {
	    double err;
	    fc = (*F)(xc);
	    v = (v0 + fc * h) * 0.5;
	    err = fabs(v - v0);
	    if (err >= 12.0 * h * eps && /*depth < MAX_DEPTH &&*/
		fabs(h) >= (1.0 + fabs(xc)) * MACHINE_PREC) {	/* �ݹ�\label{integration.c:1} */
		v = integration(a, fa, xc, fc, eps, F) +
		    integration(xc, fc, b, fb, eps, F);
	    }
	}
    }
    --depth;
    return v;
}
