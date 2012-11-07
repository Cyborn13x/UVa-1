#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{
	int i,j,k,l,m,n,t,x,y,fall,max,blank=0,test=0,flag,sum;
	char graph[55][55],a[60];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		for(i=1,graph[0][0]='+';i<55;i++) graph[0][i]='-', graph[i][0]='|';
		for(i=1;i<55;i++) for(j=1;j<55;j++) graph[i][j]=' ';
		printf("Case #%d:\n",++test);
		for(i=sum=0,m=100;a[i];i++)
		{
		      if(a[i]=='R') sum++;
		      else if(a[i]=='F') sum--;
		      if(sum<m) m=sum;
		}
		if(m<0) x=1+(-m);
		else x=1;
		y=1;
		for(i=0;a[i];i++)
		{
			if(a[i]=='R') ++y, graph[x++][y]='/';
			else if(a[i]=='C') ++y, graph[x][y]='_';
			else x--, y++, graph[x][y]='\\';
		}
		for(i=54;i>=0;i--)
		{
			j=54;
			while(graph[i][j]==' ') j--;
			if(j)
			{
			      max=i;
			      break;
			}
		}
		for(i=max,l=0;i>0;i--)
		{
			j=52;
			while(graph[i][j]==' ') j--;
			graph[i][j+1]=0;
			if(j+1>l) l=j+1;
		}
		graph[0][l++]='-', graph[0][l]=0;
		for(i=max;i>=0;i--) puts(graph[i]);
		putchar('\n');
	}
	return 0;
}
