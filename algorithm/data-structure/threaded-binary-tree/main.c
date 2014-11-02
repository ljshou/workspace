/*Copyright 2011 by wuwennongdao, All rights reserved
 *Email: liuy0711@foxmail.com
 *Blog: http://blog.csdn.net/algorithm_only
*/

#include <stdio.h>
#include <stdlib.h>
#include "thrbitree.h"

int main()
{
	bithrtree		thrt, bt;

	init_bithrtree(&bt);

	system("clear");	//for linux
//	system("cls");		//for windows

	printf("Input elemtype to create bithrtree with preorder:\n"
		"(for exemple: 1 2 3 0 0 4 5 0 6 0 0 7 0 0 0) > ");
	if ( OK != create_bithrtree(&bt))
		return -1;

	if (OK != inorder_threading(&thrt, bt))
		return -1;

	printf("After inorder threading, traverse the threading bitree:\n");
	if (OK != inorder_traverse_thr(thrt, output_data))
		return -1;

	return 0;
}
