/* $Id: integration.h,v 1.2 2005/06/20 03:28:52 zlb Exp $ */

double integration(double a, double fa, double b, double fb, double eps,
		 double(*F)(double x));
