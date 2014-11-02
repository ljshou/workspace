/* 
   Author：Tree 
   From： http://blog.csdn.net/lttree 
   Surround the Trees
   hdu 1392
   凸包周长
   */ 
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct point
{
  double x,y;
}pnt[10001],res[10001];
// 两向量叉积
double cross( point sp,point ep,point op)
{
  return (sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y);
}
// sort数组排序，比较的<号重载
bool operator < (const point &l,const point &r)
{
  return l.y<r.y || (l.y==r.y && l.x<r.x) ;
}
// 求两点间几何距离
double dis(point a,point b)
{
  return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}
int Graham( int n )
{
  int i,len,top=1;
  // 先对所有点按照极角排序
  // 纵坐标最小的排在前面，纵坐标相同，横坐标小的排在前面
  sort(pnt,pnt+n);
  // 判断点的个数是否大于2（所给的点能否构成凸包）
  if( n==0 )  return 0;res[0] = pnt[0];
  if( n==1 )  return 1;res[1] = pnt[1];
  if( n==2 )  return 2;res[2] = pnt[2];
  // 用叉积来判断后面的点是否为凸包中的点
  for( i=2;i<n;++i )
  {
    while( top && cross(pnt[i],res[top],res[top-1])>=0 )   top--;
    res[++top] = pnt[i];
  }
  len = top; res[++top] = pnt[n-2];
  // 判断最后三个点
  for(i=n-3;i>=0;--i)
  {
    while( top!=len && cross(pnt[i],res[top],res[top-1])>=0 )  top--;
    res[++top] = pnt[i];
  }
  return top;
}
int main()
{
  int n,i,len;
  double sum;
  while(scanf("%d",&n)!=EOF && n)
  {
    for(i=0;i<n;++i)
      scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
    // len为凸包数组内点的个数
    len=Graham(n);
    // 判断n为0,1,2的情况（无法构造凸包的情况）
    if(len==0 || len==1)  {printf("0\n");continue;}
    if(len==2)  {printf("%.2lf\n",dis(res[0],res[1]));continue;}

    // 求周长
    sum=0;
    for(i=0;i<len;++i)
      sum=sum+dis(res[i],res[i+1]);
    printf("%.2lf\n",sum);
  }
  return 0;
}
