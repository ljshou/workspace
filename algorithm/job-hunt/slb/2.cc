/**
 * @file 2.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-10
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
using namespace std;
typedef struct 
{
  double x , y ;
}POINT ;
POINT result[110] ;// 模拟堆栈S，保存凸包上的点
POINT tree[110] ;
int n , top ;
double Distance ( POINT p1 , POINT p2 ) 
{
  return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ) ;
}
double Multiply(POINT p1 , POINT p2 , POINT p3) // 叉积 
{
  return ( (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x) ) ;
}
int cmp ( const void *p1 , const void *p2 )
{
  POINT *p3,*p4;
  double m;
  p3 = (POINT *)p1; 
  p4 = (POINT *)p2; 
  m = Multiply(tree[0] , *p3 , *p4) ;
  if(m < 0) return 1;
  else if(m == 0 && (Distance(tree[0] , *p3) < Distance(tree[0],*p4)))
    return 1;
  else return -1;
}
void Tubao ()
{
  int i ; 
  result[0].x = tree[0].x;
  result[0].y = tree[0].y;
  result[1].x = tree[1].x;
  result[1].y = tree[1].y;
  result[2].x = tree[2].x;
  result[2].y = tree[2].y;
  top = 2;
  for ( i = 3 ; i <= n ; ++ i )
  {
    while (Multiply(result[top - 1] , result[top] , tree[i]) <= 0 )
      top -- ;                          //出栈
    result[top + 1].x = tree[i].x ;
    result[top + 1].y = tree[i].y ;
    top ++ ;
  }

}
int main ()
{
  int pos ;
  double len , temp , px , py ;
  while ( scanf ( "%d" , &n ) != EOF , n )
  {
    py = -1 ;
    for ( int i = 0 ; i < n ; ++ i )
    {
      scanf ( "%lf%lf" , &tree[i].x , &tree[i].y ) ;

    }
    if ( n == 1 )
    {
      printf ( "0.00\n" ) ;
      continue ;
    }
    else if ( n == 2 )
    {
      printf ( "%.2lf\n" , Distance(tree[0] , tree[1]) ) ;
      continue ;
    }
    for ( int i = 0 ; i < n ; ++ i )
    {
      if(py == -1 || tree[i].y < py)
      {
        px = tree[i].x;
        py = tree[i].y;
        pos = i;
      }
      else if(tree[i].y == py && tree[i].x < px)
      {
        px = tree[i].x;
        py = tree[i].y;
        pos = i;
      }
    }
    temp = tree[0].x ;                      // 找出y最小的点 
    tree[0].x = tree[pos].x ;
    tree[pos].x = temp ;
    temp = tree[0].y ;
    tree[0].y = tree[pos].y ;
    tree[pos].y = temp ;

    qsort(&tree[1],n - 1,sizeof(double) * 2,cmp);
    tree[n].x = tree[0].x;
    tree[n].y = tree[0].y;

    cout << "after sort" << endl;
    for(int i=0; i<n; ++i)
      cout << tree[i].x << " " << tree[i].y << endl;
    cout << "sort end" << endl;


    Tubao();
    for(int i=0; i<top; ++i)
      cout << result[i].x << " " << result[i].y << endl;

    len = 0.0;
    for(int i = 0 ; i < top ; i ++)
      len = len + Distance(result[i] , result[i+1]) ;
    printf("%.2lf\n",len);

  }
  return 0 ;
}
