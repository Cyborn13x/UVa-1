#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int max(int a,int b)
{
      if(a>b) return a;
      return b;
}
int min(int a,int b)
{
      if(a<b) return a;
      return b;
}
int dif(int a,int b)
{
      if(a>b) return (a-b);
      return (b-a);
}

int main()
{
	int i;
	int j;
	int n;
	int l;
	int a;
	int mn;
	int mx;
	int an;
	int mid;
      int t;
      scanf("%d",&t);
      for(i=0;i<t;i++)
      {
      	scanf("%d %d",&l,&a);
      	mid=l/2;
      	mn=99999;
      	mx=-1;
      	for(j=0;j<a;j++)
      	{
      	      scanf("%d",&n);
      		if(min(mn,dif(mid,n))<mn)
      		{
      		      mn=min(mn,dif(mid,n));
      		      if(n<=mid) an=n;
      		      else an=l-n;
      		}
      		mx=max(mx,max(dif(n,0),dif(n,l)));
      	}
      	printf("%d %d\n",an,mx);
      }
	return 0;
}
