#include<iostream>
#include<memory.h>
#include<string>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
int s[505],t[505];
char res[505],in[505];
bool ok(int i)
{
  if('0'<=res[i]&&res[i]<='9')
	return true;
  if('A'<=res[i]&&res[i]<='Z')
	return true;
  if('a'<=res[i]&&res[i]<='z')
	return true;
  return false;
}
int main()
{
  int i,j,k,ls,lt,T,a,b;//a:original base，b:new base 
  scanf("%d",&T);
  while(T--)
  {
	scanf("%d%d %s",&a,&b,&in);
	memset(res,0,sizeof(res)); 
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t)); 
	ls=strlen(in);
	for(i=0;i<ls;i++)
	{
	  if(in[i]>='0'&&in[i]<='9')
		s[ls-i-1]=in[i]-48;
	  else if(in[i]>='A'&&in[i]<='Z')
		s[ls-i-1]=in[i]-55;
	  else 
		s[ls-i-1]=in[i]-61;
	}
	k=ls;
	s[k]=0;
	for(lt=0;k;)
	{//辗转相除 
	  for(i=k;i>=1;i--)//保证s[k]=0
	  {
		s[i-1]+=s[i]%b*a;//注意+号，模拟除法 
		s[i]/=b;
	  }
	  t[lt++]=s[0]%b;
	  s[0]/=b;
	  for(;k>0&&s[k-1]==0;k--);
	}
	res[lt]=0;//清零 
	for(i=lt-1;i>=0;i--)
	{
	  if(t[i]<=9)
		res[lt-i-1]=t[i]+48;
	  else if(10<=t[i]&&t[i]<=35)
		res[lt-i-1]=t[i]+55;
	  else
		res[lt-i-1]=t[i]+61;
	  //if(!ok(lt-i-1))
	  //printf("no %d %d/n",t[i],res[lt-i-1]);
	}
	printf("%d %s/n%d %s/n/n",a,in,b,res);
  }
  return 0;
}
