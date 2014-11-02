/* $Id: integration_nr.h,v 1.2 2005/06/20 03:28:52 zlb Exp $ */

typedef struct INTERVAL_T {
    double x0, f0, x1, f1, fc;
    struct INTERVAL_T *last, *next;
} interval_t;

double
integration_nr(double a, double b, double eps, void(*F1)(double x, double *f));
