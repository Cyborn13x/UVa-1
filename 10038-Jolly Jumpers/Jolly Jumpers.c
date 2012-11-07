#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define valid(a,n) a<=n-1?1:0
#define abs(a,b) a<b?b-a:a-b

int main()
{
	int i;
	int j;
	int x;
	int y;
	int n;
	int a[3000];
	int f;
	while(scanf("%d",&n)==1)
	{
	      f=1;
		for(i=0;i<3000;i++)
		{
			a[i]=0;
		}
		scanf("%d",&x);
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&y);
			a[abs(x,y)]=1;
			x=y;
		}
		for(i=1;i<n;i++)
		{
			if(!a[i])
			{
			      f=0;
			      break;
			}
		}
		if(!f) printf("Not jolly\n");
		else printf("Jolly\n");
	}
	return 0;
}
