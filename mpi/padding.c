#include<stdio.h>
typedef struct{
     double d;
     char c;
     double d;
     char c;
} CS;
typedef struct {
	char c1;
	double d;
	char c2;
} CS1;
int main()
{
	CS a;
	CS1 b;
	printf("sizeof(CS)=%d\n", sizeof(CS));
	printf("offset(a.d)=%d, offset(a.c)=%d\n",(char *)&a.d - (char *)&a, (char *)&a.c - (char *)&a);
	printf( "sizeof(CS1)=%d\n", sizeof(CS1));
	printf( "offset(b.c1)=%d, offset(b.d)=%d, offset(b.c2)=%d\n",(char *)&b.c1 - (char *)&b, (char *)&b.d - (char *)&b,(char *)&b.c2 - (char *)&b);
	return 0;
}

